#include <fstream>
#include <vector>
#include <random>
#include <algorithm>

class Position
{
    public:
    Position(){};
    Position(int _x, int _y) : x(_x), y(_y){}
    Position(const Position &copy) : x(copy.x), y(copy.y){}

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

    Position& operator+=(const Position &second)
    {
        this->x += second.x;
        this->y += second.y;
        return *this;
    }

    bool operator==(const Position &second)
    {
        return x == second.x && y == second.y;
    }

    friend std::ostream& operator<< (std::ostream& stream, const Position& position) 
    {
        stream << position.x << ";" << position.y;
        return stream;
    }
    
    double distance(const Position &cellPos)
    {
        return std::sqrt(std::pow(x - cellPos.x, 2) + std::pow(y - cellPos.y, 2));
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
        for(auto &neighbour : neighbours)
            neighbours_indexes.push_back(neighbour->id());
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

    void addNeighbour(Cell *neighbour)
    {
        if(this == neighbour)
            throw std::logic_error("Cell " + std::to_string(index) + " cannot be neighbour of itself!");
        else if(!hasAllNeighbours())
            neighbours.push_back(neighbour);
        else
            throw std::logic_error("Cell " + std::to_string(index) + " can't have more than 4 neighbours! Couldn't add cell " + std::to_string(neighbour->index) + " as neighbour.");
    }

    std::vector<Cell*> getFullCells()
    {
        std::vector<Cell*> cells{};
        if(hasAllNeighbours())
            cells.push_back(this);

        for(auto &neighbour : neighbours)
        {
            neighbour->addNeighbour(this);
            if(neighbour->hasAllNeighbours())
                cells.push_back(neighbour);
        }
        return cells;
    }

    bool hasAllNeighbours()
    {
        return neighbours.size() == 4;
    }

    Position pos()
    {
        return positon;
    }

    size_t id()
    {
        return index;
    }

    void setIndex(size_t id)
    {
        index = id;
    }

    private:
    Position positon{};
    size_t index = 0;
    std::vector<Cell*> neighbours{};

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
        cells.push_back(new Cell(0, 0, 0));
        seed =  dev();
        rng = std::mt19937(seed);
    }
    
    ~EdensGrowthModel()
    {
        for (auto cell = cells.begin(); cell != cells.end(); ++cell)
            delete *cell;
        cells.clear();   
    }

    void generate(size_t number_of_cells = 10)
    {
        for(size_t i = 0; i < number_of_cells - 1; ++i)
        {
            appendCell();
            validateNeighbours();
        }
        afterGeneration();
    }

    private: 
    std::vector<Cell*> cells{};
    std::random_device dev;
    uint32_t seed = 0;
    std::mt19937 rng;
    size_t firstToCheck = 0;

    void storeNeighbours()
    {
        std::vector<Position> availableOffsets{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto cell = cells.begin() + firstToCheck; cell != cells.end(); ++cell)
        {
            for(auto offset = availableOffsets.begin(); offset != availableOffsets.end(); ++offset)
            {
                if((*cells.back()).pos() + *offset == (*cell)->pos())
                {
                    try
                    {
                        cells.back()->addNeighbour(*cell);
                    }
                    catch(const std::logic_error& e)
                    {
                        exportCellsData();
                        throw e;
                    }
                    
                    offset = availableOffsets.erase(offset);
                    break;
                }
            }
            if(cells.back()->hasAllNeighbours())
                break;
        }
    }
    
    void updateCells(const std::vector<Cell*> &toMove)
    {
        for(auto &cell : toMove)
        {
            if(cell->id() != firstToCheck)
            {
                Cell *tempPtr = cell;
                size_t index = cell->id();
                cells[cell->id()] = cells[firstToCheck];
                cells[firstToCheck] = tempPtr;
                cell->setIndex(firstToCheck);
                cells[index]->setIndex(index);
            }

            ++firstToCheck;
        }
    }

    void appendCell()
    {
        std::uniform_int_distribution<int> distribution(firstToCheck, cells.size() - 1);
        Cell *cellWithoutAllNeighbours = cells[distribution(rng)];
        std::vector<Position> getAvailablePositions = cellWithoutAllNeighbours->getEmptyNeighbours();
        std::uniform_int_distribution<int> distribution_(0, getAvailablePositions.size() - 1);
        cells.push_back(new Cell(getAvailablePositions[distribution_(rng)], cells.size()));
    }

    void validateNeighbours()
    {
        storeNeighbours();
        try
        {
            std::vector<Cell*> toMove = cells.back()->getFullCells();
            updateCells(toMove);
        }
        catch(const std::logic_error& e)
        {
            exportCellsData();
            throw e;
        }
    }

    void exportCellsData()
    {
        std::ofstream file("eden_model_debug.txt");
        for(auto &cell : cells)
        {
            file << cell->id() << " " << cell->pos() << "\n";
            for(auto &neighbour : cell->getNeighbours())
                file << cells[neighbour]->id() << " " << cells[neighbour]->pos() << ", ";
            file << "\n";
        }
        file.close();
    }

    void afterGeneration()
    {
        std::ofstream file("eden_model.txt");
        Position massCenter{};
        for(auto &cell : cells)
        {
            file << cell->pos() << "\n";
            massCenter += cell->pos();
        }
        file.close();
    }
};


int main()
{
    EdensGrowthModel model;
    model.generate(100000);
}