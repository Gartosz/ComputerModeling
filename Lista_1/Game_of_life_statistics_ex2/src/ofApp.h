#pragma once

#include "ofMain.h"
#include <vector>
#include <glm/gtc/random.hpp>
#include <fstream>
#include <algorithm>

class ofApp : public ofBaseApp{

	public:
		ofApp(size_t _size = 6, float alive_probability = 0.2f, size_t max_iter = 100)
		{
			ofSetVerticalSync(false);
			cell_size = _size;
			max_iteration = max_iter;
			int height = ofGetHeight() / cell_size;
			int width = ofGetWidth() / cell_size;
			for (int y = 0; y < height; ++y)
			{
				cells_matrix.push_back(std::vector<bool>{});
				for (int x = 0; x < width; ++x)
					cells_matrix[y].push_back(ofRandom(1.0) < alive_probability ? true : false);
			}
			saved_generation = cells_matrix;
			grid_size = cells_matrix.size();
		}
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:
		size_t cell_size = 6;
		std::vector<std::vector<bool>> cells_matrix{};
		std::vector<std::vector<bool>> saved_generation{};
		std::vector<std::pair<int, int>> pos_to_check = {{-1, -1}, {-1, -0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
		bool paused = true;
		int frames = 0;
		int alive = 0;
		std::vector<float> probabilities{0.05, 0.15, 0.4, 0.5, 0.7, 0.9, 0.95};
		std::vector<float>::iterator current = probabilities.begin();
		std::vector<double> final_densities{};
		std::ofstream file;
		std::ofstream summary;
		size_t grid_size = 0;
		size_t iteration = 0;
		size_t max_iteration = 0;

		void update_cells();
		void insert_cell(int y, int x);
		void reset();
		void save_frame();
		void update_probability();
		void reload_grid();
};
