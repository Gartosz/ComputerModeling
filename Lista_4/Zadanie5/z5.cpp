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

void generate_3D_walk(std::string run_time = "00000000_000000", std::size_t iterations = 1000)
{
    std::random_device dev;
    uint32_t seed = dev();
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> distribution(0, 1);

}

int main()
{
    auto const now = std::chrono::system_clock::now();
    auto const in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream run_time;
    run_time << std::put_time(std::localtime(&in_time_t), "%Y%m%d_%H%M%S");

    return 0;
}