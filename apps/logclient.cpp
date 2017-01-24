#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "net/RedisComm.h"

void do_loop(net::RedisComm& comm, const std::string& key, int num)
{
    int sleep_time = 2;


    for(int i = 0; i < num; i++)
    {
        std::string val("add this message:");
        std::ostringstream oss;
        oss << i;
        val += oss.str();
        std::cout << "sending message to redis key=" << key << " val=" << val
            << std::endl;
        comm.set_field(key, val);
        std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "not enough args... needs client number" << std::endl;
        return 0;
    }

    net::RedisComm comm("kg-net");
    const std::string host("localhost");
    uint16_t port = 6379;

    const std::string id(argv[1]);

    std::cout << "connecting to redis server at " << port << "..." << std::endl;
    comm.connect(host, port);

    std::string key("log.client.");
    key += id;
    std::cout << "key=" << key << std::endl;


    do_loop(comm, key, 5);

    return 0;
}
