#include <chrono>
#include <iostream>

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