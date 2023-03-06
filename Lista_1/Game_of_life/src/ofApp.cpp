#include "ofApp.h"

#define KEY_SPACE 32

//--------------------------------------------------------------
void ofApp::setup(){

}

void ofApp::update_cells()
{
    for (int col = 0; col < saved_generation.size(); ++col)
    {
        for (int row = 0; row < saved_generation[col].size(); ++row)
        {
            int neighbours = 0;
            for (auto &pos : pos_to_check)
                if (col + pos.first > 0 && col + pos.first < saved_generation.size() && row + pos.second > 0 && row + pos.second < saved_generation[col].size())
                    if (saved_generation[col + pos.first][row + pos.second])
                        ++neighbours;
            if (saved_generation[col][row])
                cells_matrix[col][row] = !(neighbours < 2 || neighbours > 3);

            else if (neighbours == 3)
                cells_matrix[col][row] = true;

        }
    }
    saved_generation = cells_matrix;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (!paused)
        update_cells();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int col = 0; col < cells_matrix.size(); ++col)
    {
        for (int row = 0; row < cells_matrix[col].size(); ++row)
            if (cells_matrix[col][row])
                ofDrawRectangle(row * size, col * size, size, size);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == KEY_SPACE)
        paused = !paused;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
