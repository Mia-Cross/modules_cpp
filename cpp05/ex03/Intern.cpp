#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {
    std::cout << "{creation} A random intern says hi, but nobody seems to respond\n";
    srand(time(NULL));
    this->initTab();
}
Intern::~Intern() {
    std::cout << "{destruction} A random intern was fired, everyone already forgot his name\n";
}
Intern::Intern(Intern const &ref) {
    srand(time(NULL));
    this->initTab();
    (void)ref;
}
Intern &Intern::operator=(Intern const &ref) {
    (void)ref;
    return (*this);
}

Form *Intern::makeForm(std::string const &name, std::string const &target) const
{
    Form *to_write = NULL;

    for (int i = 0; i < 4 ; i++)
    {
        try {
            to_write = (this->*createTab[i])(name, target);
            break;
        }
        catch (UnknownFormException &e) {
            std::cout << e.what();
        }
        catch (TryAgain) {}
    }
    if (to_write)
        std::cout << "Intern creates " << to_write->getName() << std::endl;
    return (to_write);
}

Form *Intern::makePPF(std::string const &name, std::string const &target) const  {
    Form *ppf = new PresidentialPardonForm(target);
    if (ppf->getName().compare(name))
    {
        delete ppf;
        throw TryAgain();
    }
    return(ppf);
}
Form *Intern::makeSCF(std::string const &name, std::string const &target) const  {
    Form *scf = new ShrubberyCreationForm(target);
    if (scf->getName().compare(name))
    {
        delete scf;
        throw TryAgain();
    }
    return(scf);
}
Form *Intern::makeRRF(std::string const &name, std::string const &target) const  {
    Form *rrf = new RobotomyRequestForm(target);
    if (rrf->getName().compare(name))
    {
        delete rrf;
        throw TryAgain();
    }
    return(rrf);
}
Form *Intern::endOfTab(std::string const &name, std::string const &target) const {
    (void)name;
    (void)target;
    throw UnknownFormException();
    return (NULL);
}

void Intern::initTab() {
    this->createTab[0] = &Intern::makePPF;
    this->createTab[1] = &Intern::makeRRF;
    this->createTab[2] = &Intern::makeSCF;
    this->createTab[3] = &Intern::endOfTab;
}
