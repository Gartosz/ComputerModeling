#include <fstream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <random>


void generate_rand(std::size_t iterations = 1000, uint32_t seed = time(NULL))
{
    srand(seed);
    std::ofstream file("rand_" + std::to_string(seed) + ".txt");
    for (int i = 0; i < iterations; ++i)
        file << ((double) rand() / (RAND_MAX)) << "\n";
    file.close();
}

void generate_mt(std::size_t iterations = 1000, uint32_t seed = time(NULL))
{
    std::mt19937 rng(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    std::ofstream file("mt_rand_" + std::to_string(seed) + ".txt");
    for (int i = 0; i < iterations; ++i)
        file << distribution(rng) << "\n";
}

int main()
{
    std::random_device dev;
    uint32_t seed = dev();
    generate_rand(1000000, seed);
    generate_mt(1000000, seed);
    return 0;
}