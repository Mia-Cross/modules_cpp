#include <iostream>
#include <string>

#define BONJOUR "du coup y s'est fait niquer sa mere"

using namespace std;
//permet d'utiliser tout ce qui se trouve dans std:: 
//sans reecrire le namespace a chaque fois

int main()
{
    string lol = "Hello World!";
    cout << lol << endl;
    cout << BONJOUR << endl;

    int a (42), b, sum;
    cin >> b;
    sum = a + b;
    std::cout << sum << std::endl;

    int x, y, z;
    y = 2 + (x = 5);
    cout << y << endl;
    x = y = z = 22;
    cout << z << endl;
    cout << y << '\n';
    cout << x << endl;

    string input;
    std::cout << "What's your name? ";
    getline (std::cin, input);
    std::cout << "Hello " << input << ".\n";

    switch (x) 
    {
        case 1:
            cout << "x is 1";
            break;
        case 2:
            cout << "x is 2";
            break;
        case 3:
        case 4:
        case 5:
            cout << "x is 3, 4 or 5";
            break;
        default:
            cout << "value of x unknown";
    }
}
/////
class Base {
    public:
        Base() {cout << "Base Constructor Called\n";}
        virtual ~Base() {cout << "Base Destructor called\n";}
};
class Derived1: public Base {
    public:
        Derived1() {cout << "Derived constructor called\n";}
        ~Derived1() {cout << "Derived destructor called\n";}
};
int main() {
    Base *b = new Derived1();
    delete b;}
// if Base destructor is virtual, both Base and Derived destructors will be called
// else if Base destructor is not virtual, only Base destructor will be called.