#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

class Slave : public Victim {
    private:
        Slave();
    public:
        Slave(std::string const name);
        virtual ~Slave();
        Slave(Slave const &ref);
        Slave &operator=(Slave const &ref);
        virtual void getPolymorphed() const;
};

Slave::Slave() : Victim("slave") {}
Slave::Slave(std::string name) : Victim(name) {
    std::cout << "Kill me plz.\n";}
Slave::Slave(Slave const &ref) : Victim(ref.getName()) {
    *this = ref;}
Slave &Slave::operator=(Slave const &ref) {
    setName(ref.getName());
    return (*this);}
Slave::~Slave() {
    std::cout << "Thank you u.u\n";}
void Slave::getPolymorphed() const {
    std::cout << getName() << " has been turned into a... I don't know, wtf is that?\n";}
std::ostream &operator<<(std::ostream &out, Slave const &in) {
    out << in.introduceThemselves();
    return (out);}

int main()
{
    Sorcerer robert("Robert", "the Magnificent");
  //  Sorcerer noName;
    Victim jim("Jimmy");
    Peon joe("Joe");
  //  Peon peon;
    Slave jack("Jack");

    std::cout << robert << jim << joe;
    std::cout << jack;
    robert.polymorph(jim);
    robert.polymorph(joe);
    robert.polymorph(jack);

    return 0;
}