#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <pthread.h>
#include <thread>
#include "Foo1.h"

using namespace std;
extern int g_debug;

int main(){
    g_debug = 0;
    std::thread([]{});
    shared_ptr<Foo2> hd2 = make_shared<Foo2>();
    cout << hd2.use_count() << endl;
    shared_ptr<void> hd22(hd2);
    cout << hd2.use_count() << endl;
    shared_ptr<Foo1> hd21 = std::static_pointer_cast<Foo1>(hd2);
    cout << hd2.use_count() << endl;
    shared_ptr<Foo1> hd221 = std::static_pointer_cast<Foo1>(hd22);
    cout << hd2.use_count() << endl;

    // hdl1->donothing();

    auto pfoo1 = new Foo1();
    auto pfoo2 = new Foo2();
    Foo2 foo2;
    auto pfoo3 = make_shared<Foo3>();
    cout << pfoo3.use_count() << endl;
    shared_ptr<void> pfoo3_void = pfoo3;
    cout << pfoo3.use_count() << endl;
    auto pfoo3_intxxx = new Foo3::intxxx();


    Foo1 *static_pfoo1_from_foo2 = static_cast<Foo1 *>(pfoo2);
    Foo2 *static_pfoo2_from_foo1 = static_cast<Foo2 *>(pfoo1);
    
    Foo1 *dynamic_pfoo1_from_foo2 = static_cast<Foo1 *>(pfoo2);
    Foo2 *dynamic_pfoo2_from_foo1 = static_cast<Foo2 *>(pfoo1);

    Foo1 *static_pfoo1_from_foo2_which_from_foo1 = static_cast<Foo1 *>(static_pfoo2_from_foo1);
    Foo2 *static_pfoo2_from_foo1_which_from_foo2 = static_cast<Foo2 *>(static_pfoo1_from_foo2);
    cout << pfoo1 << endl;
    cout << pfoo2 << endl;
    cout << static_pfoo1_from_foo2 << endl;
    cout << static_pfoo2_from_foo1 << endl;
    cout << dynamic_pfoo1_from_foo2 << endl;
    cout << dynamic_pfoo2_from_foo1 << endl;
    return 0;
}