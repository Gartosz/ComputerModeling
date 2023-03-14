#include "ofMain.h"
#include "ofApp.h"
#include <filesystem>

double calculate_standard_error(std::vector<double> density_vector)
{
	double mean = std::reduce(density_vector.begin(), density_vector.end()) / density_vector.size();
	double std_deviation = 0;
	for(auto &density : density_vector)
		std_deviation += (density - mean) * (density - mean);
	std_deviation = sqrt(std_deviation/density_vector.size());
	return std_deviation/sqrt(density_vector.size());
}
void process_files(size_t iterations_number)
{
	std::string dir = "data/";
	std::ofstream result_file("data/standard_error.txt");
	result_file << "size\t\"standard error\"\n";
	for(auto& p: filesystem::directory_iterator(dir))
	{
	}
	result_file.close();
}

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
	process_files(iterations_number);
	return 0;
}
