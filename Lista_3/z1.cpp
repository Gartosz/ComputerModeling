#include <vector>
#include <cmath>
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

    void set_position(std::size_t index, double x_value, double y_value)
    {
        positions[index].first = x_value;
        positions[index].second = y_value;
    }

    void set_velocity(std::size_t index, double x_value, double y_value)
    {
        velocities[index].first = x_value;
        velocities[index].second = y_value;
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

    system.positions[1].first = R;
    system.set_position(1, R, 0);
    system.set_velocity(1, 0, sqrt(system.masses[0]/R));
    system.rigid[0] = false;
    return 0;
}