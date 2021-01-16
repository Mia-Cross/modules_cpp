#include <iostream>
#include <stdexcept>

class Parent{public:virtual ~Parent() {}; };
class ChildA : public Parent {};
class ChildB : public Parent {};

int main()
{
    // ChildA a;
    // Parent *p = &a;
    // try {
    // ChildA &c = dynamic_cast<ChildA &>(*p);
    // std::cout << "ok cast";
    // }
    // catch (std::exception &e) {
    //     std::cout << "bad cast";
    // }

    float f = 420.042f;
    void *v = &f;
    int *p = reinterpret_cast<int*>(v);
    int &r = reinterpret_cast<int &>(v);
    printf("%f %d %f %d\n", *p, *p, r, r);
}