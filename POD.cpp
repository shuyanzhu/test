#include <iostream>
#include <type_traits>
#include <utility>

class A {
    int a;

public:
    A() = default;
    A(const A &) = delete;
    A(A &&) = default;
    ~A() = default;
};

int main() {
    A a;
    A b(std::move(a));
    //     A c(a);
    std::cout << std::is_trivial<A>::value << std::endl;
    return 0;
}