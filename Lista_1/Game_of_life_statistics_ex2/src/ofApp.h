#pragma once

#include "ofMain.h"
#include <vector>
#include <glm/gtc/random.hpp>

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
					cells_matrix[y].push_back(glm::linearRand(0, 1000) < chance_to_live * 1000 ? true : false);
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
		

	private:
		int size = 6;
		std::vector<std::vector<bool>> cells_matrix{};
		std::vector<std::vector<bool>> saved_generation{};
		std::vector<std::pair<int, int>> pos_to_check = {{-1, -1}, {-1, -0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
		bool paused = true;
};
