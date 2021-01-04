#include "Character.hpp"
#include <unistd.h>

Character::Character() {}

Character::Character(std::string const & name) : name(name), ap(40), weapon(NULL) {
    std::cout << "Character " << getName() << " is ready to kick some ass!\n";
}

Character::~Character() {
    std::cout << "Character " << getName() << " killed every enemy. What a badass!\n";
}

Character::Character(Character const &src) {
    *this = src;
}

Character &Character::operator=(Character const &that) {
    if (this != &that)
    {
        this->name = that.getName();
        this->ap = that.getAP();
    }
    return (*this);
}

void Character::recoverAP() {

    static int recovered = 0;

    if (ap <= 30 && recovered < 40)
    {
        ap += 10;
        recovered += 10;
    }
}

void Character::equip(AWeapon* wp) {
    std::cout << "Say hello to my little friend : ";
    std::cout << wp->getName();
    if (this->weapon != NULL)
        std::cout << " (dropped " << weapon->getName() << ")";
    std::cout << std::endl;
    this->weapon = wp;
}

void Character::attack(Enemy* enemy)
{
    if (this->weapon == NULL)
        return;
    this->ap -= this->weapon->getAPCost();
    if (this->ap < 0)
        return;
    std::cout << this->name << " attacks " << enemy->getType() << " with a ";
    std::cout << this->weapon->getName() << std::endl;
    this->weapon->attack();
    write(1, "#", 1);
    enemy->takeDamage(this->weapon->getDamage());
    if (enemy->getHP() <= 0)
        delete enemy;
}

std::string Character::getName() const {
    return (this->name);
}
int Character::getAP() const {
    return (this->ap);
}
AWeapon &Character::getWeaponRef() const {
    return (*this->weapon);
}
AWeapon *Character::getWeaponPtr() const {
    return (this->weapon);
}
void Character::setName(std::string name) {
    this->name = name;
}
void Character::setAP(int ap) {
    this->ap = ap;
}

std::ostream &operator<<(std::ostream &out, Character const &in) {
    out << in.getName() << " has " << in.getAP() << " AP and ";
    if (in.getWeaponPtr() == NULL)
        out << "is unarmed\n";
    else
        out  << "wields a "<< in.getWeaponRef().getName() << std::endl;
    return (out);
}