
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "cpp_redis/cpp_redis"

class CommReceiver
{
public:
    CommReceiver(const std::string& name)
    :   m_name(name)
    {

    }

    void on_reply(cpp_redis::reply& reply)
    {
        std::cout << "CommReceiver." << m_name << ".on_reply:" << reply << std::endl;
    }

private:
    std::string m_name;

};


void on_connect(cpp_redis::redis_client& client)
{
    std::cout << "connected" << std::endl;
}

void on_set(cpp_redis::reply& reply)
{
    std::cout << "val set:" << reply << std::endl;
}

void on_get(cpp_redis::reply& reply)
{
    std::cout << "val get:" << reply << std::endl;
}

void test_bad_get(cpp_redis::redis_client& client)
{
    client.get("dne", [](cpp_redis::reply& reply)
    {
        std::cout << "got dne?:" << reply << std::endl;
    });
    client.sync_commit();
}

int main(int argc, char** argv)
{

    std::cout << "test_redis_conn.hello world" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    cpp_redis::redis_client client;

    CommReceiver recv("sean");

    client.connect("127.0.0.1", 6379, &on_connect);

    std::function<void(cpp_redis::reply&)> callback = std::bind(&CommReceiver::on_reply, recv,
        std::placeholders::_1);

    //client.set("hello", "42", callback);
    /*
    client.set("hello", "42", [](cpp_redis::reply& reply) {
        std::cout << "set hello 42: " << reply << std::endl;
        // if (reply.is_string())
        //   do_something_with_string(reply.as_string())
    });
*/
    client.get("hello", callback);

/*
    // same as client.send({ "GET", "hello" }, ...)
    client.get("hello", [](cpp_redis::reply& reply) {
        std::cout << "get hello: " << reply << std::endl;
        // if (reply.is_string())
        //   do_something_with_string(reply.as_string())
    });
*/

    client.sync_commit();

    auto end = std::chrono::high_resolution_clock::now();


    std::this_thread::sleep_for(std::chrono::seconds(5));

    if (std::chrono::high_resolution_clock::is_steady) {
        std::cout << "is steady" << std::endl;
    }

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
        << std::endl;;

    test_bad_get(client);


    std::cout << "exit..." << std::endl;

    return 0;
}
