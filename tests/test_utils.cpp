#include "util/StopWatch.h"
#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char** argv)
{
    std::cout << "creating stopwatch" << std::endl;
    util::StopWatch sw;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    int64_t usec = sw.get_cur_elapsed_us();

    std::cout << "time elapsed:" << usec << std::endl;
    return 0;
}
