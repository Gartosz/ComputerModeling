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

class Cell
{
    public:
    Cell(int _x, int _y, size_t _index) : positon(_x, _y), index(_index){}

    std::vector<size_t> getNeighbours()
    {
        std::vector<size_t> neighbours_indexes{};
        
        return neighbours_indexes;
    }

    bool hasAllNeighbours()
    {
        return neighbours.size() == 4;
    }

    size_t getIndex()
    {
        return index;
    }

    std::vector<int> pos()
    {
        return positon.getPos();
    }

    private:
    Position positon{};
    size_t index = 0;
    std::vector<size_t*> neighbours;
};

class EdensGrowthModel
{
    public:
    EdensGrowthModel()
    {
        cells.push_back(Cell(0, 0, 0));
        free_spaces_cells.push_back(0);
    }

    private: 
    std::vector<Cell> cells{};
    std::vector<size_t> free_spaces_cells{};
    std::random_device dev;
    uint32_t seed = dev();
    std::mt19937 rng();
};


int main()
{

}