

link_directories("~/sandlab/github/tp/cpp_redis/build/lib")
add_executable(test_redis_conn "test_redis_conn.cpp")

target_link_libraries(test_redis_conn
    cpp_redis)


add_executable(test_utils "test_utils.cpp")


add_executable(test_net_rediscomm "test_net_rediscomm.cpp")
target_link_libraries(test_net_rediscomm
    cpp_redis
    net)

add_executable(test_threads "test_threads.cpp")

target_link_libraries(test_threads
    pthread)
