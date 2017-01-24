#include "util/StopWatch.h"
#include <iostream>
#include <thread>
#include <chrono>

void test_base_case()
{
    std::cout << "creating stopwatch" << std::endl;
    util::StopWatch sw;

    int sleep_time = 2;

    std::this_thread::sleep_for(std::chrono::seconds(sleep_time));

    int64_t usec = sw.get_cur_elapsed_us();

    std::cout << "time elapsed expected=" << sleep_time *1000000 << " actual="
        << usec << std::endl;
}


int main(int argc, char** argv)
{
    test_base_case();
    return 0;
}
