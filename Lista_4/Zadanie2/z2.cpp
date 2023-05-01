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
#include <sys/stat.h>
#include <sys/types.h>

void generate_1D_walk(std::mt19937 &rng, std::uniform_int_distribution<int> &distribution, std::size_t iterations = 1000, uint32_t seed = time(NULL), std::string run_time = "00000000_000000", std::size_t n = 0)
{
    std::ofstream file("1D/" + run_time + "/" + std::to_string(seed) + "_" + std::to_string(n) + ".txt");
    int pos_x = 0;
    file << "0 "<< pos_x << "\n";
    for (int i = 0; i < iterations;)
    {
        pos_x += distribution(rng) ? 1 : -1;
        file << ++i << " " << pos_x << "\n";
    }
    file.close();
}

int main()
{
    auto const now = std::chrono::system_clock::now();
    auto const in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream run_time;
    run_time << std::put_time(std::localtime(&in_time_t), "%Y%m%d_%H%M%S");
    int status_1 = mkdir(("1D/" + run_time.str()).c_str());
    int status_2 = mkdir(("2D/" + run_time.str()).c_str());

    if(status_1 || status_2)
        return 0;

    std::random_device dev;
    uint32_t seed = dev();
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> distribution_0_1(0, 1);
    std::uniform_int_distribution<int> distribution_0_3(0, 3);
    return 0;
}