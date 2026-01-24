#include "MyGui.h"

using namespace GEO;

int main(int argc, char** argv) {
	MyGui app("My Gui");
    app.start(argc,argv); // Geogram initialization inside
    return 0;
}