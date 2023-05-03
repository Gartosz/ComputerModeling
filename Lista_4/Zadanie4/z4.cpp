#include <fstream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <random>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <iostream>

int generate_1D_walk(std::mt19937 &rng, std::uniform_int_distribution<int> &distribution, std::size_t iterations = 1000)
{
    int pos_x = 0;
    for (int i = 0; i < iterations; ++i)
        pos_x += distribution(rng) ? 1 : -1;

    return pos_x;
}

int* generate_2D_walk(std::mt19937 &rng, std::uniform_int_distribution<int> &distribution, std::size_t iterations = 10000)
{
    std::vector<std::vector<int>> moves{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    static int pos[2] = {0, 0};
    pos[0] = 0;
    pos[1] = 0;
    std::vector<int> next_move{0, 0};
    for (int i = 0; i < iterations; ++i)
    {
        next_move = moves[distribution(rng)];
        pos[0] += next_move[0];
        pos[1] += next_move[1];
    }
    return pos;
}

int main()
{
    auto const now = std::chrono::system_clock::now();
    auto const in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream run_time;
    run_time << std::put_time(std::localtime(&in_time_t), "%Y%m%d_%H%M%S");

    std::random_device dev;
    uint32_t seed = dev();
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> distribution_0_1(0, 1);
    std::uniform_int_distribution<int> distribution_0_3(0, 3);

    return 0;
}