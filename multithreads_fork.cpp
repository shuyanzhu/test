#include <thread>
#include <unistd.h>
#include <chrono>
#include <vector>
#include <fstream>

int main(){
    std::vector<std::thread> threads;
    for(int i = 0; i < 4; i++){
        threads.emplace_back([i]{
            std::this_thread::sleep_for(std::chrono::seconds(1));
            pid_t pid = getpid();
            std::ofstream of("mt_fork" + std::to_string(pid) + "." + std::to_string(i));
            of << "donothing";
            of.flush();
        });
    }
    fork();
    pid_t pid = getpid();
    std::ofstream of("mt_fork" + std::to_string(pid) + "." + std::to_string(5));
    of.flush();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for(auto &&t:threads) t.join();
    return 0;
}