#include <iostream>
#include <map>
#include <string>

int main(){
    std::map<const std::string, int> testMap0;
    testMap0["0"] = 0;
    testMap0["1"] = 1;
    testMap0["2"] = 2;
    auto &testMap = testMap0;
    std::cout << "&testMap[\"0\"] = " << &testMap.begin()->first << std::endl;

    // 不适用auto的情况下可能会造成拷贝
    for(const std::pair<const std::string, int> &iter : testMap)
        if(iter.second == 0)
            std::cout << "const std::pair<const std::string, int> &*begin = " << &iter.first << std::endl;
    for(const std::pair<std::string, int> &iter : testMap)
        if(iter.second == 0)
            std::cout << "const std::pair<const std::string, int> &*begin = " << &iter.first << std::endl;;
    // auto: 获得一份本地拷贝
    // auto &: 仅可以对非临时变量获得一个引用（如果是局部变量，如函数返回值，则行为未定义）
    // auto &&: 可以对包括局部变量的所有情况获得引用
    // const auto &: 类似auto &&, 只不过保证只读修改
    for(const auto &iter : testMap)
        if(iter.second == 0)
            std::cout << "const auto &*begin = " << &iter.first << std::endl;;
    for(auto &iter : std::move(testMap))
        if(iter.second == 0)
            std::cout << "auto &*begin = " << &iter.first << std::endl;;
    return 0;
}