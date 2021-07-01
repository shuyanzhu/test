#include <iostream>
#include <thread>

struct D {
    int i{ 1 };
    D() { std::cout << "D()" << std::endl; }
    ~D() { std::cout << "~D()" << std::endl; }
};

void staticD() {
    static D d;
    std::cout << "In staticD" << std::endl;
}

void TLD() {
    thread_local D d;
    d.i++;
    std::cout << "In thread_local D.i: " << d.i << std::endl;
}

static D g_static_d; // main函数执行前初始化

thread_local D g_d; // 第一次访问时初始化

int main() {
    std::cout << "In main" << std::endl;

    std::cout << "&D = " << &g_d << std::endl;

    std::cout << "Pre-staticD()" << std::endl;
    staticD();
    std::cout << "Post-staticD()" << std::endl;

    std::cout << "Pre-TLD()" << std::endl;
    TLD();
    std::cout << "Post-TLD()" << std::endl;

    std::cout << "Pre-thread-TLD()" << std::endl;
    std::thread(TLD).join();
    std::cout << "Post-thread-TLD()" << std::endl;

    g_d.i++;
    std::cout << "g_d.i: " << g_d.i << std::endl;
    std::thread([] { std::cout << "In thread g_d.i: " << g_d.i << std::endl; }).join();
    return 0;
}