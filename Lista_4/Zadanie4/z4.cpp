#include <fstream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <random>
#include <vector>
int generate_1D_walk(std::mt19937 &rng, std::uniform_int_distribution<int> &distribution, std::size_t iterations = 1000)
{
    int pos_x = 0;
    for (int i = 0; i < iterations; ++i)
        pos_x += distribution(rng) ? 1 : -1;

    return pos_x;
}


int main()
{

    return 0;
}