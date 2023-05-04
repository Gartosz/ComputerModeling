#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <iostream>

int main()
{
    auto const now = std::chrono::system_clock::now();
    auto const in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream run_time;
    run_time << std::put_time(std::localtime(&in_time_t), "%Y%m%d_%H%M%S");

    return 0;
}