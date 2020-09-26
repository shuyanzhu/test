#ifndef _FOO1_
#define _FOO1_
#include <iostream>
// #include <utility>
// #include <map>


class Foo1{
public:
    typedef int intxxx;
    Foo1(){ std::cout << "Foo1 construct" << std::endl;}
    void donothing(){ std::cout << "I do nothing" << std::endl; }
    int foo1_;
};
class Foo2: public std::pair<int, int>, public Foo1
{
public:
    Foo2() { std::cout << "Foo2 construct" << std::endl; }
    int foo2_;
};
class Foo3: public Foo2{
public:
    // typedef float intxxx;
    int a;
};
// class Foo3{
    // typedef
// };
#endif