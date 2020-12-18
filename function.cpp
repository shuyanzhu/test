#include <functional>
#include <string>
#include <iostream>

using Func = std::function<void()>;

void printFunc(const Func &myfunc)
{
    Func func(myfunc);
    if (func)
        std::cout << "if(func) true" << std::endl;
    else
        std::cout << "if(func) false" << std::endl;
    if (nullptr == func)
        std::cout << "if(func == nullptr) true" << std::endl;
    else
        std::cout << "if(func == nullptr) false" << std::endl;
}

int main()
{
    Func func(nullptr);
    printFunc(func);
    return 0;
}