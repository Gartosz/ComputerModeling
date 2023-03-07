#pragma once

#include "ofMain.h"
#include <vector>
#include <glm/gtc/random.hpp>
#include <fstream>
#include <algorithm>

class ofApp : public ofBaseApp{

	public:
		ofApp(int _size = 6, float alive_probability = 0.2f)
		{
			size = _size;
			int height = ofGetHeight() / size;
			int width = ofGetWidth() / size;
			for (int y = 0; y < height; ++y)
			{
				cells_matrix.push_back(std::vector<bool>{});
				for (int x = 0; x < width; ++x)
					cells_matrix[y].push_back(ofRandom(1.0) < alive_probability ? true : false);
			}
			saved_generation = cells_matrix;
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

		void update_cells();
		void insert_cell(int y, int x);
		void reset(float alive_probability);
		void save_frame();
		void update_probability();

	private:
		int size = 6;
		std::vector<std::vector<bool>> cells_matrix{};
		std::vector<std::vector<bool>> saved_generation{};
		std::vector<std::pair<int, int>> pos_to_check = {{-1, -1}, {-1, -0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
		bool paused = true;
		int frames = 0;
		int alive = 0;
		std::vector<float> probabilities{0.05, 0.15, 0.4, 0.5, 0.7, 0.9, 0.95};
		std::vector<float>::iterator current = probabilities.begin();
		std::ofstream file;
};
