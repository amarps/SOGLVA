using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Interop;
using System.Threading;
using System.Windows;

namespace LevelEditor
{
    class OpenglHost : HwndHost
    {

        private static OpenglHost? _openglHost = new OpenglHost();

        // singleton get
        public static OpenglHost Get()
        {
            return _openglHost;
        }

        // singleton delete
        public void Delete()
        {
            SOGLVADestroy();
        }

        // application host window
        public IntPtr _openglAppHost;

        private Thread? _threadSOGLVA;

        // parent window
        public IntPtr _hwndHost;

        /// <summary>
        /// winuser constant
        /// reference https://docs.microsoft.com/en-us/windows/win32/windows-application-ui-development
        /// </summary>
        internal const int
            WsChild = 0x40000000,
            WsVisible = 0x10000000,
            LbsNotify = 0x00000001,
            HostId = 0x00000002,
            ListboxId = 0x00000001,
            WsVscroll = 0x00200000,
            WsBorder = 0x00800000;

        private OpenglHost()
        {
            _threadSOGLVA = new Thread(new ThreadStart(_Init));
            _threadSOGLVA.Start();
        }

        /// <summary>
        /// Initialiaze openglAppHost member Set SOGLVA windows parent and run the application
        /// </summary>
        private void _Init()
        {
            _openglAppHost = SOGLVAInitialize();

            SetParent(_openglAppHost, _hwndHost);

            SOGLVARunApp();
        }

        protected override HandleRef BuildWindowCore(HandleRef hwndParent)
        {
            
            _hwndHost = IntPtr.Zero;

            _hwndHost = CreateWindowEx(0, "static", "",
                WsChild | WsVisible,
                0, 0,
                800, 600,
                hwndParent.Handle,
                (IntPtr)HostId,
                IntPtr.Zero,
                0);

            return new HandleRef(this, _hwndHost);
        }

        protected override void DestroyWindowCore(HandleRef hwnd)
        {
            SOGLVADestroy();
        }

        // SOLGVA API -----------------------------------------

        // Destroy The SOGLVA Window
        [DllImport("../../SOGLVA.dll")]
        internal static extern void SOGLVADestroy();

        // run SOGLVA Application
        [DllImport("../../SOGLVA.dll")]
        internal static extern void SOGLVARunApp();

        // Initialize SOGLVA and get the HWND
        [DllImport("../../SOGLVA.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr SOGLVAInitialize();

        // WIN32 API -------------------------------------------

        //PInvoke declarations
        [DllImport("user32.dll", EntryPoint = "CreateWindowEx", CharSet = CharSet.Unicode)]
        internal static extern IntPtr CreateWindowEx(int dwExStyle,
            string lpszClassName,
            string lpszWindowName,
            int style,
            int x, int y,
            int width, int height,
            IntPtr hwndParent,
            IntPtr hMenu,
            IntPtr hInst,
            [MarshalAs(UnmanagedType.AsAny)] object pvParam);

        // Destroy HWND
        [DllImport("user32.dll", EntryPoint = "DestroyWindow", CharSet = CharSet.Unicode)]
        internal static extern bool DestroyWindow(IntPtr hwnd);

        // Set HWND Window parent
        [DllImport("user32.dll", CharSet = CharSet.Unicode)]
        internal static extern IntPtr SetParent(IntPtr child, IntPtr hwnd);

        // Show HWND Window parent
        [DllImport("user32.dll", CharSet = CharSet.Unicode)]
        internal static extern bool ShowWindow(IntPtr child, int nCmd);
    }
}
