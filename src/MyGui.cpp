// An application based on Geogram's SimpleMeshApplication
// see https://github.com/BrunoLevy/geogram/wiki/Applications

#include <geogram/basic/file_system.h>

#include "MyGui.h"

MyGui::MyGui(const std::string &name) :
    SimpleMeshApplication(name),
    show_ImGui_demo_window_(false) // by default, the ImGui demo window is not displayed
    {}

MyGui::~MyGui() {}

// Drawing of the whole GUI
void MyGui::draw_gui() {
    SimpleMeshApplication::draw_gui();
    if(show_ImGui_demo_window_) {
        ImGui::ShowDemoWindow();
    }
}

// Drawing of the 3D scene
void MyGui::draw_scene() {
    SimpleMeshApplication::draw_scene();
    // you can add a scene overlay here
    // see glup*() function
}

// The right panel
void MyGui::draw_object_properties() {
    ImGui::TextUnformatted("Hello world!");
    // see the ImGui demo window for all the controls & widgets possible
}

// The horizontal menu bar
void MyGui::draw_menu_bar() {
    SimpleMeshApplication::draw_menu_bar();
    if(ImGui::BeginMainMenuBar()) {
        // extend the main menu bar
        if(ImGui::BeginMenu("My new sub-menu")) {
            if(ImGui::MenuItem(
                "Show ImGui demo window", // label
                NULL, // no shortcut
                show_ImGui_demo_window_ // marked as selected if `show_ImGui_demo_window_` is true
            )) {
                // on click, toggle `show_ImGui_demo_window_`
                show_ImGui_demo_window_ = !show_ImGui_demo_window_;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

// Allow new file extensions when opening a file, eg .custom files
std::string MyGui::supported_read_file_extensions() {
    return SimpleMeshApplication::supported_read_file_extensions() + ";custom";
}

// Function called when the user:
// - passed command line arguments, eg `./gui input-file.mesh other-input-file.txt`
// or
// - clicked on File > Load
// or
// - dragged and dropped a file to the window
bool MyGui::load(const std::string& filename) {
    if(FileSystem::extension(filename) == "custom") {
        // TODO custom load() behevior
        return true;
    }
    else {
        // default behavior
        return SimpleMeshApplication::load(filename);
    }
}

// Allow new file extensions when saving as file, eg .custom files
std::string MyGui::supported_write_file_extensions() {
    return SimpleMeshApplication::supported_write_file_extensions() + ";custom";
}

// Function called when the user clicked on File > Save as
bool MyGui::save(const std::string& filename) {
    if(FileSystem::extension(filename) == "custom") {
        // TODO custom save() behevior
        return true;
    }
    else {
        // default behavior
        return SimpleMeshApplication::save(filename);
    }
}