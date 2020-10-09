#include <iostream>

struct X {
    X()  { std::cout << "default constructor in "<< this << std::endl; }
    ~X() { std::cout << "destructor in "       <<  this << std::endl; }

    X(const X&)            { std::cout << "copy constructor in " << this << std::endl;         }
    X& operator=(const X&) { std::cout << "copy assignment operator\n"; return *this;}
};

X f() {
    // in c++11, -fno-copy-elistion, def(tmp in f)->copy(x)->des(tmp in f)->copy(tmp in main)->des(x)->copy(a)->des(tmp in main)->des(a)
    // in C++17, -fno-copy-elision, def->copy->des->des
    // in c++17/c++11/c++03, def->des 
   X x = X();
   return x;

    // c++17 copy-elision test
    // -fno-copy-elsion, def->des
    // so, c++17 ask copy-elision in function call, dont ask copy-elision optimation in one function
    // return X();
}

int main() {
    std::cout << "sizeof(X) = " << sizeof(X) << std::endl;
    // &a0:         0x7ffffffedc28
    // tmp in main: 0x7ffffffedc20
    // x:           0x7ffffffedbc0 + 96
    // tmp in f:    0x7ffffffedbb8 + 8
    X a0 = f();
    std::cout << std::endl;
    // &a1:         0x7ffffffedc00
    // x:           0x7ffffffedbc0 + 64
    // tmp in f:    0x7ffffffedbb8 + 8
    const X &a1 = f();
    std::cout << std::endl;
    // // &a2:         0x7ffffffedbf0 
    // // x:           0x7ffffffedbc0 + 48
    // // tmp in f:    0x7ffffffedbb8 + 8
    X &&a2 = f();
    std::cout << std::endl;
    // std::cout << "Debug" << std::endl;
    // destroy a2
    // destroy a1
    // destroy a0
    return 0;
}
