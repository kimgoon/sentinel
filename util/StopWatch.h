#pragma

#include <chrono>

namespace util {

class TimeConstants {
public:
    static const int USEC_PER_MSEC = 1000;
};

class StopWatch {
public:
    StopWatch()
    :   m_start(std::chrono::high_resolution_clock::now())
    {
    }

    int64_t get_cur_elapsed_us() const {
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end-m_start).count();
    }

    int64_t get_cur_elapsed_ms() const {
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(
            end-m_start).count()/TimeConstants::USEC_PER_MSEC;
    }


private:
    //std::chrono::time_point m_start;
     std::chrono::time_point<std::chrono::high_resolution_clock> m_start;

};
} // close namespace util
