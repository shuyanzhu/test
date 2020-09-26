#include <iostream>

struct X {
    X()  { std::cout << "default constructor" << std::endl; }
    ~X() { std::cout << "destructor in "       <<  this << std::endl; }

    X(const X&)            { std::cout << "copy constructor\n";         }
    X& operator=(const X&) { std::cout << "copy assignment operator\n"; }
};

X f() {
    // in c++11, -fno-copy-elistion, def->copy->des->copy(tmp)->des(x)->copy(a)->des(tmp)->des(a)
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
    X &&a = f();
    std::cout << "Debug" << std::endl;
    return 0;
}
