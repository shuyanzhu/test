#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

int main() {
    // 不能自举，编译器会首先生成一个数组
    // 然后把数组的首地址和值传进去
    auto x = std::initializer_list<int>{1, 2, 3};
    std::vector<std::vector<std::string>> tmp;
    std::string s = "123";
    std::vector<std::string> sv = { s };
    // tmp.emplace_back(s);
    tmp.emplace_back(sv);
    // auto v2 = std::vector<std::string>(s);
    return 0;
}