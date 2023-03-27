#include <vector>
class System_2d
{
    public:
    System_2d(std::size_t N = 3, double mass = 1, double _dt = 0.001) : n(N), dt(_dt) 
    {
        positions.resize(N);
        velocities.resize(N);
        masses.resize(N);
        std::fill(masses.begin(), masses.end(), mass);
    }

    std::size_t n = 0;
    double dt = 0.1;
    std::vector<std::pair<double, double>> positions{};
    std::vector<std::pair<double, double>> velocities{};
    std::vector<double> masses {};
    std::vector<bool> rigid{true};
};

int main()
{
    System_2d system(2);
    std::size_t R = 5;

    return 0;
}