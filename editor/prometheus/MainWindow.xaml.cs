using System;
using System.Runtime.InteropServices;
using System.Security.Permissions;
using System.Windows;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Media;
using System.Windows.Threading;

namespace prometheus_editor
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            this.CommandBindings.Add(new CommandBinding(SystemCommands.CloseWindowCommand, this.OnCloseWindow));
            this.CommandBindings.Add(new CommandBinding(SystemCommands.MaximizeWindowCommand, this.OnMaximizeWindow, this.OnCanResizeWindow));
            this.CommandBindings.Add(new CommandBinding(SystemCommands.MinimizeWindowCommand, this.OnMinimizeWindow, this.OnCanMinimizeWindow));
            this.CommandBindings.Add(new CommandBinding(SystemCommands.RestoreWindowCommand, this.OnRestoreWindow, this.OnCanResizeWindow));

            HRESULT.Check(SetSize(512, 512));
            HRESULT.Check(SetAlpha(false));
            HRESULT.Check(SetNumDesiredSamples(4));

            CompositionTarget.Rendering += new EventHandler(CompositionTarget_Rendering);

            _adapterTimer = new DispatcherTimer();
            _adapterTimer.Tick += new EventHandler(AdapterTimer_Tick);
            _adapterTimer.Interval = new TimeSpan(0, 0, 0, 0, 500);
            _adapterTimer.Start();

            _sizeTimer = new DispatcherTimer(DispatcherPriority.Render);
            _sizeTimer.Tick += new EventHandler(SizeTimer_Tick);
            _sizeTimer.Interval = new TimeSpan(0, 0, 0, 0, 200);
            _sizeTimer.Start();
        }

        private void OnCanResizeWindow(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = this.ResizeMode == ResizeMode.CanResize || this.ResizeMode == ResizeMode.CanResizeWithGrip;
        }

        public void OnCanMinimizeWindow(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = this.ResizeMode != ResizeMode.NoResize;
        }

        public void OnCloseWindow(object target, ExecutedRoutedEventArgs e)
        {
            SystemCommands.CloseWindow(this);
        }

        public void OnMaximizeWindow(object target, ExecutedRoutedEventArgs e)
        {
            SystemCommands.MaximizeWindow(this);
        }

        public void OnMinimizeWindow(object target, ExecutedRoutedEventArgs e)
        {
            SystemCommands.MinimizeWindow(this);
        }

        public void OnRestoreWindow(object target, ExecutedRoutedEventArgs e)
        {
            SystemCommands.RestoreWindow(this);
        }

        ~MainWindow()
        {
            Destroy();
        }

        void AdapterTimer_Tick(object sender, EventArgs e)
        {
            POINT p = new POINT(imgelt.PointToScreen(new Point(0, 0)));

            HRESULT.Check(SetAdapter(p));
        }

        void SizeTimer_Tick(object sender, EventArgs e)
        {
            uint actualWidth = (uint)imgelt.ActualWidth;
            uint actualHeight = (uint)imgelt.ActualHeight;
            if ((actualWidth > 0 && actualHeight > 0) &&
                (actualWidth != (uint)d3dimg.Width || actualHeight != (uint)d3dimg.Height))
            {
                HRESULT.Check(SetSize(actualWidth, actualHeight));
            }
        }

        void CompositionTarget_Rendering(object sender, EventArgs e)
        {
            RenderingEventArgs args = (RenderingEventArgs)e;

            if (d3dimg.IsFrontBufferAvailable && _lastRender != args.RenderingTime)
            {
                IntPtr pSurface = IntPtr.Zero;
                HRESULT.Check(GetBackBufferNoRef(out pSurface));
                if (pSurface != IntPtr.Zero)
                {
                    d3dimg.Lock();
                    d3dimg.SetBackBuffer(D3DResourceType.IDirect3DSurface9, pSurface);
                    HRESULT.Check(Render());
                    d3dimg.AddDirtyRect(new Int32Rect(0, 0, d3dimg.PixelWidth, d3dimg.PixelHeight));
                    d3dimg.Unlock();

                    _lastRender = args.RenderingTime;
                }
            }
        }

        DispatcherTimer _sizeTimer;
        DispatcherTimer _adapterTimer;
        TimeSpan _lastRender;

        [DllImport("D3DContent.dll")]
        static extern int GetBackBufferNoRef(out IntPtr pSurface);

        [DllImport("D3DContent.dll")]
        static extern int SetSize(uint width, uint height);

        [DllImport("D3DContent.dll")]
        static extern int SetAlpha(bool useAlpha);

        [DllImport("D3DContent.dll")]
        static extern int SetNumDesiredSamples(uint numSamples);

        [StructLayout(LayoutKind.Sequential)]
        struct POINT
        {
            public POINT(Point p)
            {
                x = (int)p.X;
                y = (int)p.Y;
            }

            public int x;
            public int y;
        }

        [DllImport("D3DContent.dll")]
        static extern int SetAdapter(POINT screenSpacePoint);

        [DllImport("D3DContent.dll")]
        static extern int Render();

        [DllImport("D3DContent.dll")]
        static extern void Destroy();
    }

    public static class HRESULT
    {
        [SecurityPermissionAttribute(SecurityAction.Demand, Flags = SecurityPermissionFlag.UnmanagedCode)]
        public static void Check(int hr)
        {
            Marshal.ThrowExceptionForHR(hr);
        }
    }
}
