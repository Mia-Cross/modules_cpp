#include "Character.hpp"

Character::Character() {}

Character::~Character() {
    std::cout << "Character [" << name << "] says bye!\n";
}
Character::Character(std::string const &name) : name(name) {
    std::cout << "Character [" << name << "] says hello!\n";
}
Character::Character(Character const &ref) {
    *this = ref;
}
Character &Character::operator=(Character const &ref) {
    if (this != &ref)
    {
        this->name = ref.name;
        for (unsigned int i = 0; i < ref.inventory.size(); i++)
            this->inventory[i] = ref.inventory[i];
    }
}

std::string const &Character::getName() const {
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (this->inventory.size() > 3)
        std::cout << "Inventory full\n";
    else
    {
        this->inventory.push_back(m);
        std::cout << "Inventory : added " << m->getType() <<" in slot ";
        std::cout << this->inventory.size() + 1 << std::endl;
    }
}

void Character::unequip(int idx) 
{
    if (idx >= (int)this->inventory.size() || idx < 0)
        std::cout << "Slot empty\n";
    else
    {
        AMateria &to_del = *this->inventory[idx];
        std::cout << "Inventory : removed " << to_del.getType();
        std::cout << " from slot " << idx << std::endl;
        this->inventory.erase(this->inventory.begin() + idx);
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= (int)this->inventory.size() || idx < 0)
        std::cout << "Slot empty\n";
    else
    {
        AMateria &to_use = *this->inventory[idx];
        to_use.use(target);
    }
}