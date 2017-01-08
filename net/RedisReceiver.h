#pragma once

#include "cpp_redis/cpp_redis"


namespace net {

class RedisReceiver {
public:

    virtual void on_set_reply();
    virtual void on_get_reply();

};
} // close namespace net
