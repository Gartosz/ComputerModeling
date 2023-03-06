#include "ofApp.h"

#define KEY_SPACE 32

//--------------------------------------------------------------
void ofApp::setup(){

}

void ofApp::update_cells()
{
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
