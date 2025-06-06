using System;
using System.Runtime.InteropServices;
using Gtk;

namespace PDUGenUI
{

    public class App
    {
        private struct UIContents
        {
            public Window window;
        }
        private static UIContents _ui;

        private static bool _initialized = false;

        public static void Run()
        {
            if (!App._initialized)
                throw new Exception("GTK Application has not been initialized");

            App._ui.window.ShowAll();

            Application.Run();
        }
        public static void Init()
        {
            if (App._initialized)
                throw new Exception("GTK Application is already created");

            App.CreateUI();

            App._initialized = true;
        }
        private static void CreateUI()
        {
            Application.Init();

            App._ui.window = new Window("PDUGen");
            App._ui.window.SetDefaultSize(800, 800);
            App._ui.window.DeleteEvent += (o, args) => Application.Quit();

            Fixed frame = [];
            Button btn = new("");
            btn.SetSizeRequest(75, 20);

            btn.Clicked += (sender, e) =>
            {
                // Point_t p = cslib.point_create(420,69);

                // IntPtr pointPtr = Marshal.AllocHGlobal(Marshal.SizeOf<Point_t>());
                // Marshal.StructureToPtr(p, pointPtr, false);

                // cslib.point_print(ref p);

                // MessageDialog dialog = new MessageDialog(
                //     App._ui.window,
                //     DialogFlags.Modal,
                //     MessageType.Info,
                //     ButtonsType.Ok,
                //     $"Point Created: ({p.x}, {p.y})"
                // );

                // dialog.Run();
                // dialog.Destroy();

                // cslib.point_manip(ref p);
                // Console.WriteLine($"[UI] Point edited -> {p.x}, {p.y}");

                // Marshal.FreeHGlobal(pointPtr);
            };

            frame.Put(btn, 50, 50);

            App._ui.window.Add(frame);
        }
    }

}