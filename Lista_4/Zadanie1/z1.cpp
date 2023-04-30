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

int main()
{
    return 0;
}