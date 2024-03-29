#pragma once

class TriangleRenderer : public Renderer
{
public:
	static HRESULT Create(IDirect3D9 *pD3D, IDirect3D9Ex *pD3DEx, HWND hwnd, UINT uAdapter, Renderer **ppRenderer);
	~TriangleRenderer();

	HRESULT Render();

protected:
	HRESULT Init(IDirect3D9 *pD3D, IDirect3D9Ex *pD3DEx, HWND hwnd, UINT uAdapter);

private:
	TriangleRenderer();

	IDirect3DVertexBuffer9 *m_pd3dVB;
};