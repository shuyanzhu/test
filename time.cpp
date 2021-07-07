#include <chrono>
#include <iostream>
#include <sys/syscall.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
class Ticker {
public:
    Ticker()
        : lastTime_(std::chrono::steady_clock::now()) {}
    void setNow() { lastTime_ = std::chrono::steady_clock::now(); }
    std::chrono::milliseconds elapsedTime() {
        auto now = std::chrono::steady_clock::now();
        std::chrono::milliseconds ret = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime_);
        lastTime_ = now;
        return ret;
    }

private:
    decltype(std::chrono::steady_clock::now()) lastTime_;
};

void printGettimeCost() {
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000; i++) {
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed1 = end - start;
    std::cout << "10000 times empty for cost: " << elapsed1.count() << "ms" << std::endl;
    struct timeval tv;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000; i++) {
        // std::chrono::steady_clock::now();
        // syscall(134);
        // read(0, 0, 0);
        // gettimeofday(&tv, nullptr);
        syscall(96, &tv, nullptr);
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed2 = end - start;
    std::cout << "10000 times empty for cost: " << elapsed2.count() << "ms" << std::endl;
    std::cout << "Get time cost: " << (elapsed2 - elapsed1).count() / 10000 * 1000000 << "ns" << std::endl;
}

int main() {
    printGettimeCost();
    // auto start = std::chrono::steady_clock::now();
    // long long num{ (int64_t)10e9 };
    // while (num--)
    //     ;
    // auto end = std::chrono::steady_clock::now();
    // std::chrono::duration<double> elapsed = end - start;
    // std::cout << "运行时间: " << elapsed.count() << "s" << std::endl;
    return 0;
}
