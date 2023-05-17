#include <fstream>
#include <vector>
class Position
{
    public:
    Position(int _x, int _y) : x(_x), y(_y){}

    private:
    int x = 0;
    int y = 0;
};

class EdensGrowthModel
{
    public:
    EdensGrowthModel()
    {
        cells.push_back(Position(0,0));
        free_spaces_cells.push_back(0);
    }

    private: 
    std::vector<Position> cells{};
    std::vector<size_t> free_spaces_cells{};
};


int main()
{

}