#pragma once
#include <iostream>

template <typename T> class Foo {
    T foo_;

public:
    Foo(T a)
        : foo_(a){};
    void print();
};

// WEAK
template <typename T> void Foo<T>::print() { std::cout << foo_ << std::endl; }