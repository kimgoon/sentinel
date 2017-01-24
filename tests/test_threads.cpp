#include <iostream>
#include <thread>
#include <string>

void do_work(const std::string& name)
{
    for(int i = 0; i < 5; i++)
    {
        std::cout << "do_work." << name << "=" << i << std::endl;
    }
}



int main(int argc, char** argv)
{
    std::string name("kimgoon");
    std::cout << "starting test_threads..." << std::endl;
    std::thread t(do_work, name);

    std::cout << "waiting..." << std::endl;
    t.join();

    return 0;
}
