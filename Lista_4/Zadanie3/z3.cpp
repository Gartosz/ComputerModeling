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

    std::ofstream file(run_time.str() + ".txt");
    size_t count_1 = 0, count_30 = 0;
    int final_pos = 0;
    for (std::size_t i = 0; i < 10000; ++i)
    {
        final_pos = generate_1D_walk(rng, distribution_0_1, 1000);
        file << final_pos << "\n";
    }
    
    std::cout << count_1 << " " << count_30;
    return 0;
}