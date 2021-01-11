#include "Character.hpp"

Character::Character() {}

Character::~Character() {
    for (unsigned int i = 0; i < inventory.size(); i++)
        delete inventory[i];
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
    return (*this);
}

std::string const &Character::getName() const {
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        std::cout << "No matching materia type in memory\n";
    else if (this->inventory.size() > 3)
        std::cout << "Inventory full\n";
    else
    {
        std::cout << "|Inventory| Added " << m->getType() <<" in slot " << this->inventory.size();
        this->inventory.push_back(m);
        std::cout << "\tInventorySize |" << this->inventory.size() <<"|\n";
    }
}

void Character::unequip(int idx) 
{
    if (idx >= (int)this->inventory.size() || idx < 0)
        std::cout << "Slot empty\n";
    else
    {
        AMateria &to_del = *this->inventory[idx];
        std::cout << "|Inventory| Removed " << to_del.getType();
        std::cout << " from slot " << idx << std::endl;
        std::cout << "\tInventorySize |" << this->inventory.size() - 1 <<"|\n";
        this->inventory.erase(this->inventory.begin() + idx);
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= (int)this->inventory.size() || idx < 0)
        std::cout << "Slot empty\n";
    else
    {
        AMateria *to_use = this->inventory[idx];
        std::cout << "|Inventory| Using " << to_use->getType() << " from slot " << idx;
        std::cout << "\tInventorySize |" << this->inventory.size() - 1 <<"|\n";
        to_use->use(target);
        delete this->inventory[idx];
        this->inventory.erase(this->inventory.begin() + idx);
    }
}