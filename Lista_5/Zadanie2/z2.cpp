#include <vector>
#include <cmath>
#include <string>
#include <iostream>

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

    Position& operator/=(const size_t &value)
    {
        this->x = std::round(1.0*this->x/value);
        this->y = std::round(1.0*this->y/value);
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

};

class DlaCluster
{

};

int main()
{

}