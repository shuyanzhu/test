// template <typename T>
// class TestFooBar{};
// template class vector<int>;
// class Bar{
//     class Foo;
//     using TestFoo = TestFooBar<Foo>;
//     // typedef pair<int, Foo> TestFoo;
//     public:
//     TestFoo foo_;
//     int i;
// };
// // class Bar::Foo{int i;};
// int main(int argc, char **argv){
//     auto a = new Bar();
//     cout << a << endl;
//     vector<int> test{10, 5};
//     for(auto &&i: test)
//         cout << i << endl;
//     return 0;
// }
int g_debug = 1;