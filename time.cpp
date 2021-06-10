#include <chrono>
#include <iostream>
class Ticker{
public:
    Ticker(): lastTime_(std::chrono::steady_clock::now()){}
    void setNow(){ lastTime_ = std::chrono::steady_clock::now(); }
    std::chrono::milliseconds elapsedTime(){
        auto now = std::chrono::steady_clock::now();
        std::chrono::milliseconds ret = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime_);
        lastTime_ = now;
        return ret;
    }
private:
    decltype(std::chrono::steady_clock::now()) lastTime_;
};

int main() {
    auto start = std::chrono::steady_clock::now();
    long long num{ (int64_t)10e9 };
    while (num--)
        ;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "运行时间: " << elapsed.count() << "s" << std::endl;
    return 0;
}
