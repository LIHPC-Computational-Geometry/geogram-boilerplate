#include "MyGui.h"

using namespace GEO;

int main(int argc, char** argv) {
    initialize(); // initialize Geogram first
	MyGui app("My Gui");
    app.start(argc,argv);
    return 0;
}