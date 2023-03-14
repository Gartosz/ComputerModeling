#include "ofMain.h"
#include "ofApp.h"


//========================================================================
int main( )
{
	size_t iterations_number = 100;
	// Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(900, 900);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN
	
	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>(10, 0.55, iterations_number));
	ofRunMainLoop();

}
