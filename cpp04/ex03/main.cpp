#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Fire : public AMateria {
    public :
        Fire();
        ~Fire();
        Fire(std::string const &type);
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);};
Fire::Fire() : AMateria("fire") {}
Fire::Fire(std::string const &type) : AMateria(type) {}
Fire::~Fire() {}
void Fire::use(ICharacter &target) {
    AMateria::use(target);
    std::cout << "* sends a heat wave towards " << target.getName();
    std::cout << " *\txp = " << this->getXP() - 10 << " -> " << this->getXP() << std::endl;}
AMateria* Fire::clone() const {
    return (new Fire("fire"));}

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Fire());
    src->learnMateria(new Cure());
   // src->learnMateria(new Ice());

   ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire");
    me->equip(tmp);
    tmp = src->createMateria("poison");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->unequip(3);
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->use(0, *bob);

    ICharacter &other = *me;
    other.use(0, *bob);

    MateriaSource iceSource;
    MateriaSource cureSource;

    iceSource.learnMateria(new Ice());
    tmp = iceSource.createMateria("ice");
    delete tmp;
    cureSource.learnMateria(new Cure());
    tmp = cureSource.createMateria("cure");
    delete tmp;

    iceSource = cureSource;
    tmp = iceSource.createMateria("ice");
    tmp = iceSource.createMateria("cure");
    delete tmp;

    delete bob;
    delete me;
    delete src;

    return 0;

    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // ICharacter* me = new Character("me");

    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // ICharacter* bob = new Character("bob");
    // me->use(0, *bob);
    // me->use(1, *bob);
    // delete bob;
    // delete me;
    // delete src;
    // return 0;

}