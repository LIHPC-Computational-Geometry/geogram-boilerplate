#include "shared.h"

#include <geogram/mesh/mesh.h> // for GEO::Mesh
#include <geogram/mesh/mesh_io.h> // for GEO::mesh_save()
#include <geogram/basic/logger.h> // for GEO::Logger()

#include <iostream>

using namespace GEO;

int main(int argc, char** argv) {
	initialize(); // initialize Geogram first
    
    Mesh cube;
    Logger::out("Custom feat.") << "Creating cube mesh..." << std::endl;
    create_cube_mesh(cube);

    // write to file as .obj
    if(!mesh_save(cube,"cube.obj")) {
        Logger::out("I/O") << "Unable to write mesh to file" << std::endl;
        return 1;
    }
    return 0;
}