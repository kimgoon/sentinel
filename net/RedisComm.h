#pragma once


#include <string>
#include "cpp_redis/cpp_redis"

namespace net {
class RedisComm {


public:
    RedisComm(const std::string &name);
    bool connect(const std::string& host, uint16_t port);
    bool disconnect();
    bool set_field(const std::string& key, const std::string& val);
    bool get_field(const std::string& key, std::string& val);

    // TODO
    bool get_field_async(const std::string& key, void* cb);
    bool set_field_async(const std::string& key, const std::string& val, void* cb);
    bool commit_async();


    bool add_receiver();

protected:
    void on_disconnect(cpp_redis::redis_client& client);
    void on_get_reply_as_string(cpp_redis::reply& reply, std::string& ret_val);
    void publish_value(const std::string& src, std::string& dest);

private:
    std::string m_name;

    std::string m_host;
    uint16_t m_port;

    cpp_redis::redis_client m_client;


};

} // close namespace net
