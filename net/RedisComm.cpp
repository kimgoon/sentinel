#include "RedisComm.h"


#include <thread>
#include <chrono>

namespace net {


RedisComm::RedisComm(const std::string& name)
:   m_name(name), m_host(""), m_port(0)
{
    std::cout << "created rediscomm name=" << m_name << std::endl;
}

bool RedisComm::connect(const std::string& host, uint16_t port)
{
    m_host = host;
    m_port = port;
    std::cout << "try to connect to redis at " << m_host << ":" << port << std::endl;
    std::function<void(cpp_redis::redis_client&)> cb
        = std::bind(&RedisComm::on_disconnect, this, std::placeholders::_1);
    m_client.connect(m_host, m_port, cb);
    return true;
}

bool RedisComm::disconnect()
{
    return true;
}

bool RedisComm::set_field(const std::string& key, const std::string& val)
{
    m_client.set(key, val);

    m_client.sync_commit();

    return true;
}

bool RedisComm::get_field(const std::string& key, std::string& val)
{

    //std::function<void(cpp_redis::reply&, std::string&)> cb
    //    = std::bind(&RedisComm::on_get_reply_as_string, this, std::placeholders::_1, std::placeholders::_2);
    //m_client.get(key, cb);
    std::string to;
    m_client.get(key, [&](cpp_redis::reply& reply)
    {
        if (reply.is_string()) {
            val = reply.as_string();
        }
    });

    m_client.sync_commit();
    return true;
}

// call back definitions

void RedisComm::on_disconnect(cpp_redis::redis_client& client)
{
    std::cout << "on_disconnect=" << std::endl; //<< client << std::endl;
}

void RedisComm::on_get_reply_as_string(cpp_redis::reply& reply, std::string& ret_val)
{
    std::cout << "on_get_reply_as_string reply=" << reply << std::endl;
    if (reply.is_string()) {
        ret_val = reply.as_string();
    }

}


} // close namespace net
