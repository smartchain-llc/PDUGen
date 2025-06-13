#include "resources/main/MainWindow.h"

struct WindowAttributes {
  static constexpr uint16_t width{800}, height{600};
  static constexpr uint16_t centerX{width / 2};
  static constexpr uint16_t centerY{height / 2};
};

struct WorldCoords {
  float x, y, z;
};

struct MouseCoords {
  WorldCoords world;
};
static MouseCoords Mouse;

static constexpr WorldCoords Bullseye = {
    .x = 293.898, .y = -5241.917, .z = 3609.536};
// 5km points form bullseye
// W: .x = 288.964

static constexpr double scaleX = 1.017;
static constexpr double scaleY = 17.473;

void mouseToWorld(const int &x) { Mouse.world.x = x * scaleX; }

int main(int argc, char **argv) {
  auto app = pdugen_ui::MainWindow::create();
  return app->run(argc, argv);
}

// static void run(GtkApplication *app, gpointer data) {
//   GtkWidget *window = gtk_application_window_new(app);
//   gtk_window_set_title(GTK_WINDOW(window), "PDUGen");
//   gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);

//   // GtkWidget *text_view = gtk_text_view_new();
//   GtkWidget *area = gtk_drawing_area_new();
//   // gtkdraw
//   gtk_window_set_child(GTK_WINDOW(window), area);

//   gtk_widget_show(window);
// }
// int main(int argc, char **argv) {
//   GtkApplication *app =
//       gtk_application_new("com.scllc.pdugenui", G_APPLICATION_DEFAULT_FLAGS);

//   g_signal_connect(app, "activate", G_CALLBACK(run), NULL);
//   int status = g_application_run(G_APPLICATION(app), argc, argv);
//   g_object_ref(app);
//   return status;
// }