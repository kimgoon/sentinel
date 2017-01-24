link_directories("~/sandlab/github/tp/cpp_redis/build/lib")
add_executable(logclient "logclient.cpp")

target_link_libraries(logclient
    cpp_redis
    net)

