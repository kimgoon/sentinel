#include <iostream>
#include <thread>
#include <chrono>

void do_send_loop() {

    int sleep_time = 2;
    int id = 0;

    while(true) {
        std::cout << "sending msg id=" << id << "..."
        // send
        id++;
        std::this_thread::sleep_for(std::chrono::seconds(sleep_time));

    }
}

int main()
{
    uint16_t port = 6379;

    do_send_loop();
    return 0;
}
