#pragma once

#include "ofMain.h"
#include <vector>
#include <glm/gtc/random.hpp>

class ofApp : public ofBaseApp{

	public:
		ofApp(int height = 200, int width = 200)
		{
			for (int y = 0; y < height; ++y)
			{
				cells_matrix.push_back(std::vector<bool>{});
				for (int x = 0; x < width; ++x)
					cells_matrix[y].push_back(glm::linearRand(0, 1000) > 950 ? true : false);
			}
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
		int size = 4;
		std::vector<std::vector<bool>> cells_matrix{};
		
};
