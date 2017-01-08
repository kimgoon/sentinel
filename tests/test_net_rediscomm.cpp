#include "net/RedisComm.h"


int main()
{
    net::RedisComm comm("kg-net");

    uint16_t port = 6379;
    std::cout << "connecting to... " << port << std::endl;
    comm.connect("localhost", port);

    const std::string key("name");
    const std::string val("kimgoon");

    comm.set_field(key, val);

    std::string ret_val;
    comm.get_field(key, ret_val);

    std::cout << "ret val=" << ret_val << std::endl;


    return 0;
}
