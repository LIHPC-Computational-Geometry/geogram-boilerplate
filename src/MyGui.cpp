// An application based on Geogram's SimpleMeshApplication
// see https://github.com/BrunoLevy/geogram/wiki/Applications

#include "MyGui.h"
#include "shared.h"

#include <geogram/basic/file_system.h> // FileSystem::extension()
#include <geogram/basic/numeric.h> // for GEO::Numeric::float32 and Numeric::random_float32()

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
    SimpleMeshApplication::draw_object_properties();
    ImGui::SeparatorText("Added");
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

void MyGui::geogram_initialize(int argc, char** argv) {
    SimpleMeshApplication::geogram_initialize(argc,argv);
    if (filenames().empty()) { // if no filename were given through the command line
        Logger::out("Custom feat.") << "Creating cube mesh..." << std::endl;
        create_cube_mesh(mesh_);
        mesh_gfx_.set_mesh(&mesh_);
        // create an attribute, per-vertex here, with random values in [0,1]
        Attribute<Numeric::float32> my_custom_attribute(mesh_.vertices.attributes(),"my_custom_attribute");
        for(index_t vertex_index = 0; vertex_index < mesh_.vertices.nb(); vertex_index++) {
            my_custom_attribute[vertex_index] = Numeric::random_float32();
        }
        show_attributes_ = true;
        current_colormap_index_ = 2; // an index in SimpleApplication::colormaps_, see SimpleApplication::init_colormaps()
        attribute_subelements_ = MESH_VERTICES;
        attribute_name_ = "my_custom_attribute";
        attribute_ = "vertices.my_custom_attribute";
        attribute_min_ = 0.0f;
        attribute_max_ = 1.0f;
    }
}