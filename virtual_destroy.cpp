#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <pthread.h>
#include <thread>

using namespace std;

class Base{
public:
    int i;
    // 合成的析构函数也是非虚的
    ~Base(){ std::cout << "Base destroy" << std::endl;}
};

class Derive: public Base{
public:
    ~Derive(){ std::cout << "Derive destroy" << std::endl;}
};

int main(){
    Base *derive = new Derive();
    Derive();
    delete derive;
    return 0;
}