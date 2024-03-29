#include "stdafx.hpp"

const static TCHAR szAppName[] = TEXT("D3DImageSample");
typedef HRESULT(WINAPI *DIRECT3DCREATE9EXFUNCTION)(UINT SDKVersion, IDirect3D9Ex**);

RendererManager::RendererManager()
	:
	m_pD3D(NULL),
	m_pD3DEx(NULL),
	m_cAdapters(0),
	m_hwnd(NULL),
	m_pCurrentRenderer(NULL),
	m_rgRenderers(NULL),
	m_uWidth(1024),
	m_uHeight(1024),
	m_uNumSamples(0),
	m_fUseAlpha(false),
	m_fSurfaceSettingsChanged(true)
{

}

RendererManager::~RendererManager()
{
	DestroyResources();

	if (m_hwnd)
	{
		DestroyWindow(m_hwnd);
		UnregisterClass(szAppName, NULL);
	}
}

HRESULT RendererManager::Create(RendererManager **ppManager)
{
	HRESULT hr = S_OK;

	*ppManager = new RendererManager();
	IFCOOM(*ppManager);

Cleanup:
	return hr;
}

HRESULT RendererManager::EnsureRenderers()
{
	HRESULT hr = S_OK;

	if (!m_rgRenderers)
	{
		IFC(EnsureHWND());

		assert(m_cAdapters);
		m_rgRenderers = new Renderer*[m_cAdapters];
		IFCOOM(m_rgRenderers);
		ZeroMemory(m_rgRenderers, m_cAdapters * sizeof(m_rgRenderers[0]));

		for (UINT i = 0; i < m_cAdapters; ++i)
		{
			IFC(TriangleRenderer::Create(m_pD3D, m_pD3DEx, m_hwnd, i, &m_rgRenderers[i]));
		}

		// Default to the default adapter 
		m_pCurrentRenderer = m_rgRenderers[0];
	}

Cleanup:
	return hr;
}

HRESULT RendererManager::EnsureHWND()
{
	HRESULT hr = S_OK;

	if (!m_hwnd)
	{
		WNDCLASS wndclass;

		wndclass.style = CS_HREDRAW | CS_VREDRAW;
		wndclass.lpfnWndProc = DefWindowProc;
		wndclass.cbClsExtra = 0;
		wndclass.cbWndExtra = 0;
		wndclass.hInstance = NULL;
		wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wndclass.lpszMenuName = NULL;
		wndclass.lpszClassName = szAppName;

		if (!RegisterClass(&wndclass))
		{
			IFC(E_FAIL);
		}

		m_hwnd = CreateWindow(szAppName,
			TEXT("D3DImageSample"),
			WS_OVERLAPPEDWINDOW,
			0,                   // Initial X
			0,                   // Initial Y
			0,                   // Width
			0,                   // Height
			NULL,
			NULL,
			NULL,
			NULL);
	}

Cleanup:
	return hr;
}

HRESULT RendererManager::EnsureD3DObjects()
{
	HRESULT hr = S_OK;

	HMODULE hD3D = NULL;
	if (!m_pD3D)
	{
		hD3D = LoadLibrary(TEXT("d3d9.dll"));
		DIRECT3DCREATE9EXFUNCTION pfnCreate9Ex = (DIRECT3DCREATE9EXFUNCTION)GetProcAddress(hD3D, "Direct3DCreate9Ex");
		if (pfnCreate9Ex)
		{
			IFC((*pfnCreate9Ex)(D3D_SDK_VERSION, &m_pD3DEx));
			IFC(m_pD3DEx->QueryInterface(__uuidof(IDirect3D9), reinterpret_cast<void **>(&m_pD3D)));
		}
		else
		{
			m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
			if (!m_pD3D)
			{
				IFC(E_FAIL);
			}
		}

		m_cAdapters = m_pD3D->GetAdapterCount();
	}

Cleanup:
	if (hD3D)
	{
		FreeLibrary(hD3D);
	}

	return hr;
}

void RendererManager::CleanupInvalidDevices()
{
	for (UINT i = 0; i < m_cAdapters; ++i)
	{
		if (FAILED(m_rgRenderers[i]->CheckDeviceState()))
		{
			DestroyResources();
			break;
		}
	}
}

HRESULT RendererManager::GetBackBufferNoRef(IDirect3DSurface9 **ppSurface)
{
	HRESULT hr = S_OK;

	// Make sure we at least return NULL
	*ppSurface = NULL;

	CleanupInvalidDevices();

	IFC(EnsureD3DObjects());

	//
	// Even if we never render to another adapter, this sample creates devices
	// and resources on each one. This is a potential waste of video memory,
	// but it guarantees that we won't have any problems (e.g. out of video
	// memory) when switching to render on another adapter. In your own code
	// you may choose to delay creation but you'll need to handle the issues
	// that come with it.
	//

	IFC(EnsureRenderers());

	if (m_fSurfaceSettingsChanged)
	{
		if (FAILED(TestSurfaceSettings()))
		{
			IFC(E_FAIL);
		}

		for (UINT i = 0; i < m_cAdapters; ++i)
		{
			IFC(m_rgRenderers[i]->CreateSurface(m_uWidth, m_uHeight, m_fUseAlpha, m_uNumSamples));
		}

		m_fSurfaceSettingsChanged = false;
	}

	if (m_pCurrentRenderer)
	{
		*ppSurface = m_pCurrentRenderer->GetSurfaceNoRef();
	}

Cleanup:
	// If we failed because of a bad device, ignore the failure for now and 
	// we'll clean up and try again next time.
	if (hr == D3DERR_DEVICELOST)
	{
		hr = S_OK;
	}

	return hr;
}

HRESULT RendererManager::TestSurfaceSettings()
{
	HRESULT hr = S_OK;

	D3DFORMAT fmt = m_fUseAlpha ? D3DFMT_A8R8G8B8 : D3DFMT_X8R8G8B8;

	// 
	// We test all adapters because because we potentially use all adapters.
	// But even if this sample only rendered to the default adapter, you
	// should check all adapters because WPF may move your surface to
	// another adapter for you!
	//

	for (UINT i = 0; i < m_cAdapters; ++i)
	{
		// Can we get HW rendering?
		IFC(m_pD3D->CheckDeviceType(
			i,
			D3DDEVTYPE_HAL,
			D3DFMT_X8R8G8B8,
			fmt,
			TRUE
		));

		// Is the format okay?
		IFC(m_pD3D->CheckDeviceFormat(
			i,
			D3DDEVTYPE_HAL,
			D3DFMT_X8R8G8B8,
			D3DUSAGE_RENDERTARGET | D3DUSAGE_DYNAMIC, // We'll use dynamic when on XP
			D3DRTYPE_SURFACE,
			fmt
		));

		// D3DImage only allows multisampling on 9Ex devices. If we can't 
		// multisample, overwrite the desired number of samples with 0.
		if (m_pD3DEx && m_uNumSamples > 1)
		{
			assert(m_uNumSamples <= 16);

			if (FAILED(m_pD3D->CheckDeviceMultiSampleType(
				i,
				D3DDEVTYPE_HAL,
				fmt,
				TRUE,
				static_cast<D3DMULTISAMPLE_TYPE>(m_uNumSamples),
				NULL
			)))
			{
				m_uNumSamples = 0;
			}
		}
		else
		{
			m_uNumSamples = 0;
		}
	}

Cleanup:
	return hr;
}

void RendererManager::DestroyResources()
{
	SAFE_RELEASE(m_pD3D);
	SAFE_RELEASE(m_pD3DEx);

	for (UINT i = 0; i < m_cAdapters; ++i)
	{
		delete m_rgRenderers[i];
	}
	delete[] m_rgRenderers;
	m_rgRenderers = NULL;

	m_pCurrentRenderer = NULL;
	m_cAdapters = 0;

	m_fSurfaceSettingsChanged = true;
}

void RendererManager::SetSize(UINT uWidth, UINT uHeight)
{
	if (uWidth != m_uWidth || uHeight != m_uHeight)
	{
		m_uWidth = uWidth;
		m_uHeight = uHeight;
		m_fSurfaceSettingsChanged = true;
	}
}

void RendererManager::SetAlpha(bool fUseAlpha)
{
	if (fUseAlpha != m_fUseAlpha)
	{
		m_fUseAlpha = fUseAlpha;
		m_fSurfaceSettingsChanged = true;
	}
}

void RendererManager::SetNumDesiredSamples(UINT uNumSamples)
{
	if (m_uNumSamples != uNumSamples)
	{
		m_uNumSamples = uNumSamples;
		m_fSurfaceSettingsChanged = true;
	}
}

void RendererManager::SetAdapter(POINT screenSpacePoint)
{
	CleanupInvalidDevices();

	//
	// After CleanupInvalidDevices, we may not have any D3D objects. Rather than
	// recreate them here, ignore the adapter update and wait for render to recreate.
	//

	if (m_pD3D && m_rgRenderers)
	{
		HMONITOR hMon = MonitorFromPoint(screenSpacePoint, MONITOR_DEFAULTTONULL);

		for (UINT i = 0; i < m_cAdapters; ++i)
		{
			if (hMon == m_pD3D->GetAdapterMonitor(i))
			{
				m_pCurrentRenderer = m_rgRenderers[i];
				break;
			}
		}
	}
}

HRESULT RendererManager::Render()
{
	return m_pCurrentRenderer ? m_pCurrentRenderer->Render() : S_OK;
}