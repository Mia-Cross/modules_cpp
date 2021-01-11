#include "Character.hpp"

Character::Character() : name(""), nbMateria(0) {
    memset(inventory, 0, sizeof(AMateria *) * 4);
}
Character::~Character() {
    this->clearMemory();
    std::cout << "Character [" << name << "] says bye!\n";
}
Character::Character(std::string const &name) : name(name), nbMateria(0) {
    memset(inventory, 0, sizeof(AMateria *) * 4);
    std::cout << "Character [" << name << "] says hello!\n";
}
Character::Character(Character const &ref) : name(ref.name), nbMateria(ref.nbMateria) {
    // std::cout << "Copy called\n";
    memset(inventory, 0, sizeof(AMateria *) * 4);
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            this->inventory[i] = ref.inventory[i]->clone();
    }
}
Character &Character::operator=(Character const &ref) {
    //std::cout << "Assignation called\n";
    if (this != &ref)
    {
        this->name = ref.name;
        this->clearMemory();
        this->nbMateria = ref.getCount();
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
                this->inventory[i] = ref.inventory[i]->clone();
        }
    }
    return (*this);
}
///////////////////// COPLIEN /////////////////////////////////

std::string const &Character::getName() const {
    return (this->name);
}
int Character::getCount() const {
    return (this->nbMateria);
}

///////////////////// GETTERS /////////////////////////////////

void Character::equip(AMateria* m)
{
    if (!m)
        std::cout << "No matching materia type in memory\n";
    else if (this->nbMateria > 3)
        std::cout << "Inventory full\n";
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i] == NULL)
            {
                this->inventory[i] = m;
                std::cout << "|Inventory| Equiped " << m->getType() <<" in slot " << i;
                std::cout << "\tInventorySize | " << this->nbMateria << " -> "<< this->nbMateria + 1 <<" |\n";
                ++this->nbMateria;
                return ;
            }
        }
    }
}

void Character::unequip(int idx) 
{
    if (idx > 3 || idx < 0 || this->inventory[idx] == NULL)
        std::cout << "Slot empty\n";
    else
    {
        std::cout << "|Inventory| Removed " << this->inventory[idx]->getType() << " from slot ";
        this->inventory[idx] = NULL;
        std::cout << idx << "\tInventorySize | " << nbMateria << " -> " << nbMateria - 1 << " |\n";
        --this->nbMateria;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx > 3 || idx < 0 || this->inventory[idx] == NULL)
        std::cout << "Slot empty\n";
    else
    {
        std::cout << "|Inventory| Using " << this->inventory[idx]->getType() << " from slot " << idx << "\n";
        this->inventory[idx]->use(target);
    }
}
///////////////////// METHODS  /////////////////////////////////

void Character::clearMemory()
{
    std::cout << "Clearing " << this->nbMateria << " materias\n";
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
    this->nbMateria = 0;
    memset(inventory, 0, sizeof(AMateria *) * 4);
}