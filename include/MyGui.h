#pragma once

#include <geogram_gfx/gui/simple_mesh_application.h>
#include <string>

using namespace GEO;

class MyGui : public SimpleMeshApplication {
public:
    MyGui(const std::string &name);
    ~MyGui();
    void draw_gui() override;
    void draw_scene() override;
    void draw_object_properties() override;
    void draw_menu_bar() override;
    std::string supported_read_file_extensions() override;
    bool load(const std::string& filename) override;
    std::string supported_write_file_extensions() override;
    bool save(const std::string& filename) override;

protected:
    bool show_ImGui_demo_window_; // true if the ImGui demo window is currently displayed
};