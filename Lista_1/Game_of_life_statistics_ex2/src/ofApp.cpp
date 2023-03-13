#include "ofApp.h"
#include <algorithm>
#include <string>

#define KEY_SPACE 32

//--------------------------------------------------------------
void ofApp::setup()
{
    file.open("data/probability_0_05.txt");
    summary.open("data/density_summary.txt");
    summary << "probability	\"final density\"\n";
    file << "--- \"Iteration 0\" ---\n";
    paused = false;
}

void ofApp::update_cells()
{
    alive = 0;
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
            {
                ++alive;
                cells_matrix[col][row] = !(neighbours < 2 || neighbours > 3);
            }

            else if (neighbours == 3)
                cells_matrix[col][row] = true;
        }
    }
    saved_generation = cells_matrix;
    save_frame();
    ++frames;
}

void ofApp::update_probability()
{
    file.close();
    double mean_density = std::reduce(final_densities.begin(), final_densities.end()) / max_iteration;
    summary << *current << " " << mean_density << std::endl;
    final_densities.resize(0);
    iteration = 0;
    if (++current == probabilities.end())
    {
        ofExit();
        return;
    }
    std::string probability = std::to_string(*current);
    std::replace(probability.begin(), probability.end(), '.', '_');
    std::replace(probability.begin(), probability.end(), ',', '_');
    file.open("data/probability_" + probability + ".txt");
    reset();
}

void ofApp::reload_grid()
{
    final_densities.push_back(1.0 * alive / (grid_size * grid_size));
    ++iteration;
    if (iteration >= max_iteration)
        update_probability();
    file << "--- \"Iteration " + to_string(iteration) + "\" ---\n";
    reset();
}

//--------------------------------------------------------------
void ofApp::update()
{
    if (frames >= 500)
        reload_grid();

    else if (!paused)
        update_cells();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (int row = 0; row < cells_matrix.size(); ++row)
        for (int col = 0; col < cells_matrix[row].size(); ++col)
            if (cells_matrix[row][col])
                ofDrawRectangle(col * cell_size, row * cell_size, cell_size, cell_size);
}

void ofApp::reset()
{
    for (auto &row : cells_matrix)
        for (auto col : row)
            col = ofRandom(1.0) < *current ? true : false;

    saved_generation = cells_matrix;
    frames = 0;
}

void ofApp::save_frame()
{
    file << frames << " " << 1.0 * alive / (grid_size * grid_size) << std::endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == KEY_SPACE)
        paused = !paused;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

void ofApp::insert_cell(int y, int x)
{
    x /= cell_size;
    y /= cell_size;
    if (y > 0 && y < cells_matrix.size() && x > 0 && x < cells_matrix[0].size())
        cells_matrix[y][x] = true;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    insert_cell(y, x);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    insert_cell(y, x);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
