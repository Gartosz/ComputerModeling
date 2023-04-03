#include <vector>
#include <cmath>
#include <ranges>
#include <algorithm>
#include <functional> 
#include <iostream>
#include <fstream>


template <typename T_vec, typename T_var>
std::vector <T_vec> operator* (std::vector <T_vec> vec, const T_var var)
{
    std::transform (vec.begin (), vec.end (), vec.begin (), std::bind(std::multiplies<T_vec>(), std::placeholders::_1, var)) ;
    return vec;
}

template <typename T_vec, typename T_var>
std::vector <T_vec> operator/ (std::vector <T_vec> vec, const T_var var)
{
    std::transform (vec.begin (), vec.end (), vec.begin (), std::bind(std::divides<T_vec>(), std::placeholders::_1, var)) ;
    return vec;
}

template<typename _Ty1, typename _Ty2>
std::ostream& operator<<(std::ostream& _os, const std::pair<_Ty1, _Ty2>& _p) {
    _os << _p.first << ' ' << _p.second;
    return _os;
}

class System_2d
{
    public:
    System_2d(std::size_t N = 3, double mass = 1, double _dt = 0.001, double R = 5) : n(N), dt(_dt) , r(R)
    {
        positions.resize(N, std::make_pair(0, 0));
        velocities.resize(N, std::make_pair(0, 0));
        masses.resize(N, mass);
        rigid.resize(N, true);
        file.open("data_out.txt");
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

    void begin(std::size_t duration)
    {
        for (double time = 0; time <= duration; time += dt)
            for (std::size_t i = 0; i < positions.size(); ++i)
                if (rigid[i])  
                {
                    std::vector<double> force {};
                    for (std::size_t j = 0; j < positions.size(); ++j)
                        if (j != i)
                            update_force(force, calculate_force(std::make_pair(i, j)));
                    update_object(i, force);
                }
    }

    std::size_t n = 0;
    double dt = 0.1;
    double r = 0;
    std::vector<std::pair<double, double>> positions{};
    std::vector<std::pair<double, double>> velocities{};
    std::vector<double> masses {};
    std::vector<bool> rigid{true};

    private:

    std::ofstream file;

    void update_force(std::vector<double> &force, std::vector<double> comp_force)
    {
        force.insert(std::end(force), std::begin(comp_force), std::end(comp_force));
    }

    void update_velocity(std::pair<double, double> &velocity, std::vector<double> acceleration)
    {
        velocity.first += acceleration[0];
        velocity.second += acceleration[1];
    }

    void update_position(std::pair<double, double> &position, std::pair<double, double> velocity)
    {
        position.first += velocity.first;
        position.second += velocity.second;
    }

    void update_object(std::size_t index, std::vector<double> force)
    {
        update_velocity(velocities[index], force);
        update_position(positions[index], velocities[index]);
    }

    std::vector<double> calculate_force(std::pair<std::size_t, std::size_t> indexes)
    {
        double temp_force = (1*masses[indexes.first]*masses[indexes.second])/pow(distance(positions[indexes.first], positions[indexes.second]), 3);
        return distance_vector(positions[indexes.first], positions[indexes.second]) * temp_force;
    }

    double distance(std::pair<double, double> pos1, std::pair<double, double> pos2)
    {
        return sqrt(pow(pos2.first - pos1.first, 2)+pow(pos2.second - pos1.second, 2));
    }

    std::vector<double> distance_vector(std::pair<double, double> pos1, std::pair<double, double> pos2)
    {
        std::vector<double> result(2);
        result[0] = pos2.first - pos1.first;
        result[1] = pos2.second - pos1.second;
        return result;
    }
};

int main()
{
    System_2d system(2);
    std::size_t R = 5;

    system.positions[1].first = R;
    system.set_position(1, R, 0);
    system.set_velocity(1, 0, sqrt(system.masses[0]/R));
    system.rigid[0] = false;
    system.begin(100);
    return 0;
}