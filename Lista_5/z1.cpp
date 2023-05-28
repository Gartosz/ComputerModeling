#include <fstream>
#include <vector>
#include <random>

class Position
{
    public:
    Position(){};
    Position(int _x, int _y) : x(_x), y(_y){}
    Position(Position &copy) : x(copy.x), y(copy.y){}

    std::vector<int> getPos()
    {
        return std::vector<int> {x, y};
    }

    void setPos(int _x, int _y) 
    {
        x = _x;
        y = _y;
    }

    Position operator+(const Position &second)
    {
        return Position(x + second.x, y + second.y);
    }

    bool operator==(const Position &second)
    {
        return x == second.x && y == second.y;
    }

    private:
    int x = 0;
    int y = 0;
};

class Cell
{
    public:
    Cell(int _x, int _y, size_t _index) : positon(_x, _y), index(_index){}
    Cell(Position pos, size_t _index) : positon(pos), index(_index){}

    std::vector<size_t> getNeighbours()
    {
        std::vector<size_t> neighbours_indexes{};
        return neighbours_indexes;
    }

    std::vector<Position> getEmptyNeighbours()
    {
        std::vector<Position> emptyNeighbours{};
        std::vector<Position> availableOffsets{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (auto &offset: availableOffsets)
        {
            Position newPos = positon + offset;
            if(posNotExists(newPos))
                emptyNeighbours.push_back(newPos);
        }

        return emptyNeighbours;
    }
    bool hasAllNeighbours()
    {
        return neighbours.size() == 4;
    }

    Position pos()
    {
        return positon;
    }

    std::vector<int> pos()
    {
        return positon.getPos();
    }

    private:
    Position positon{};
    size_t index = 0;
    std::vector<Cell*> neighbours;

    bool posNotExists(const Position &posToVerify)
    {
        for(auto &neighbour: neighbours)
        {
            if(neighbour->positon == posToVerify)
                return false;
        }
        return true;
    }
};

class EdensGrowthModel
{
    public:
    EdensGrowthModel()
    {
        cells.push_back(Cell(0, 0, 0));
        free_spaces_cells.push_back(0);
        seed =  dev();
        rng = std::mt19937(seed);
    }

    private: 
    std::vector<Cell> cells{};
    std::vector<size_t> free_spaces_cells{};
    std::random_device dev;
    uint32_t seed = 0;
    std::mt19937 rng;
};


int main()
{

}