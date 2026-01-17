#include <geogram/mesh/mesh.h> // for GEO::Mesh
#include <geogram/mesh/mesh_io.h> // for GEO::mesh_save()
#include <geogram/basic/logger.h> // for GEO::Logger()

#include <iostream>

using namespace GEO;

int main(int argc, char** argv) {
	initialize(); // initialize Geogram first
    
    // create a triangulated cube
    // from https://github.com/LIHPC-Computational-Geometry/validity-first-polycube-labeling/blob/main/tests/main.cpp
    Mesh cube;
    index_t index_of_first_vertex = cube.vertices.create_vertices(8);
    geo_assert(index_of_first_vertex == 0);
    cube.vertices.point(0) = GEO::vec3(0.0, 0.0, 1.0);
    cube.vertices.point(1) = GEO::vec3(0.0, 0.0, 0.0);
    cube.vertices.point(2) = GEO::vec3(1.0, 0.0, 1.0);
    cube.vertices.point(3) = GEO::vec3(1.0, 0.0, 0.0);
    cube.vertices.point(4) = GEO::vec3(0.0, 1.0, 1.0);
    cube.vertices.point(5) = GEO::vec3(0.0, 1.0, 0.0);
    cube.vertices.point(6) = GEO::vec3(1.0, 1.0, 1.0);
    cube.vertices.point(7) = GEO::vec3(1.0, 1.0, 0.0);
    index_t index_of_first_facet = cube.facets.create_triangles(12);
    geo_assert(index_of_first_facet == 0);
    // facet 0
    cube.facets.set_vertex(0,0,0);
    cube.facets.set_vertex(0,1,1);
    cube.facets.set_vertex(0,2,3);
    // facet 1
    cube.facets.set_vertex(1,0,0);
    cube.facets.set_vertex(1,1,3);
    cube.facets.set_vertex(1,2,2);
    // facet 2
    cube.facets.set_vertex(2,0,1);
    cube.facets.set_vertex(2,1,4);
    cube.facets.set_vertex(2,2,5);
    // facet 3
    cube.facets.set_vertex(3,0,0);
    cube.facets.set_vertex(3,1,4);
    cube.facets.set_vertex(3,2,1);
    // facet 4
    cube.facets.set_vertex(4,0,5);
    cube.facets.set_vertex(4,1,6);
    cube.facets.set_vertex(4,2,7);
    // facet 5
    cube.facets.set_vertex(5,0,4);
    cube.facets.set_vertex(5,1,6);
    cube.facets.set_vertex(5,2,5);
    // facet 6
    cube.facets.set_vertex(6,0,2);
    cube.facets.set_vertex(6,1,3);
    cube.facets.set_vertex(6,2,7);
    // facet 7
    cube.facets.set_vertex(7,0,2);
    cube.facets.set_vertex(7,1,7);
    cube.facets.set_vertex(7,2,6);
    // facet 8
    cube.facets.set_vertex(8,0,0);
    cube.facets.set_vertex(8,1,2);
    cube.facets.set_vertex(8,2,4);
    // facet 9
    cube.facets.set_vertex(9,0,2);
    cube.facets.set_vertex(9,1,6);
    cube.facets.set_vertex(9,2,4);
    // facet 10
    cube.facets.set_vertex(10,0,1);
    cube.facets.set_vertex(10,1,5);
    cube.facets.set_vertex(10,2,7);
    // facet 11
    cube.facets.set_vertex(11,0,1);
    cube.facets.set_vertex(11,1,7);
    cube.facets.set_vertex(11,2,3);

    // write to file as .obj
    if(!mesh_save(cube,"cube.obj")) {
        Logger::out("I/O") << "Unable to write mesh to file" << std::endl;
        return 1;
    }
    return 0;
}