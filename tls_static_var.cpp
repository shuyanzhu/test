#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

int addOne(){
    static int testNum(1);
    //static atomic<int> testNum(1);
    return testNum++;    
}

int main(){
    auto add10000 = []{ for(int i = 0; i < 10000; i++) addOne(); };
    thread t1(add10000);
    thread t2(add10000);
    t1.join();
    t2.join();
    cout << addOne() << endl;
    return 0;
}
