#include "Foo.hpp"
#include <iostream>
extern void a();
extern void b();
int main() {
    a();
    b();
    std::cout << Foo::foo() << std::endl;
    return 0;
}