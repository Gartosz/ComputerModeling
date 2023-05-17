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
    EdensGrowthModel()
    {

    }

    private: 
    std::vector<Position> cells{};
    std::vector<size_t> free_spaces_cells{};
};


int main()
{

}