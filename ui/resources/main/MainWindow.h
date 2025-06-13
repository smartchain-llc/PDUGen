#pragma once
#include "cairomm/refptr.h"
#include "gdk/gdk.h"
#include "glibmm/refptr.h"
#include "gtkmm/application.h"
#include "gtkmm/builder.h"
#include "gtkmm/drawingarea.h"
#include "gtkmm/textbuffer.h"
#include "gtkmm/textview.h"
#include "sigc++/functors/mem_fun.h"
#include <PDUCreator.h>
#include <cstdio>
#include <gtkmm.h>
#include <iostream>
#include <json.hpp>
#include <resources.h>
#include <thread>

using namespace std::chrono_literals;
namespace pdugen_ui {

class MainWindow : public Gtk::Application {
public:
  static Glib::RefPtr<MainWindow> create() {
    return Glib::RefPtr<MainWindow>(new MainWindow());
  }

protected:
  std::thread _m_entGen;
  std::atomic<bool> _m_quitThread{false};
  Gtk::TextView *entityTxtOutput{nullptr};

  MainWindow() : Gtk::Application("com.smartchain-llc.PDUGenUI") {}

  void on_activate() override {
    auto builder =
        Gtk::Builder::create_from_file(ResourceFile("pdugen-glade.glade"));

    Gtk::Window *window = nullptr;
    builder->get_widget("windowMain", window);

    Gtk::DrawingArea *area{nullptr};
    builder->get_widget("areaDraw1", area);

    builder->get_widget("textViewPDUs", entityTxtOutput);

    if (area)
      area->signal_draw().connect(sigc::mem_fun(*this, &MainWindow::on_draw),
                                  false);

    if (entityTxtOutput) {
      auto buffer = entityTxtOutput->get_buffer();
      if (!buffer)
        std::cerr << "Textview buffer is null" << std::endl;
      buffer->set_text("Test");
    }

    if (window) {
      add_window(*window);
      window->show_all();
      window->signal_delete_event().connect(
          sigc::mem_fun(*this, &MainWindow::on_window_delete), false);
    }

    _m_entGen = std::thread(
        [](Glib::RefPtr<Gtk::TextBuffer> buf) {
          char msg[256];

          for (auto i = 0; i < 5; i++) {
            std::this_thread::sleep_for(1s);
            auto e = PDUCreator::CreateEntity();
            sprintf(msg, "Entity <%d> created...\n", e.id.num);
            buf->insert(buf->end(), msg);
          }
        },
        entityTxtOutput->get_buffer());
  }
  bool on_window_delete(GdkEventAny *e) {
    _m_quitThread = true;
    _m_entGen.join();
  }
  bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    cr->set_source_rgb(1.0, 0.2, 0.2);
    cr->arc(200, 150, 100, 0, 2 * M_PI);
    cr->fill();
    return true;
  }
};

} // namespace pdugen_ui