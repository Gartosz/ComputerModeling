#include <fstream>
#include <vector>
#include <random>

class Position
{
    public:
    Position();
    Position(int _x, int _y) : x(_x), y(_y){}

    std::vector<int> getPos()
    {
        return std::vector<int> {x, y};
    }

    void setPos(int _x, int _y) 
    {
        x = _x;
        y = _y;
    }

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
    std::random_device dev;
    uint32_t seed = dev();
    std::mt19937 rng();
};


int main()
{

}