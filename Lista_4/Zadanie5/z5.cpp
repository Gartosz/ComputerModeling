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
#include <algorithm>

void generate_3D_walk(std::string run_time = "00000000_000000", std::size_t iterations = 1000)
{
    std::random_device dev;
    uint32_t seed = dev();
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> distribution(0, 1);

    std::vector<int> pos(3, 0);
    std::vector<int> next_move{0, 0};
    std::ofstream file(run_time + ".txt");
    file << pos[0] << " " << pos[1] << " " << pos[2] << "\n";
    for (int i = 0; i < iterations; ++i)
    {
        std::for_each(pos.begin(), pos.end(), [&distribution, &rng](int &step) {step += distribution(rng) ? 1 : -1;});
        file << pos[0] << " " << pos[1] << " " << pos[2] << "\n";
    }
    file.close();
}

int main()
{
    auto const now = std::chrono::system_clock::now();
    auto const in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream run_time;
    run_time << std::put_time(std::localtime(&in_time_t), "%Y%m%d_%H%M%S");

    return 0;
}