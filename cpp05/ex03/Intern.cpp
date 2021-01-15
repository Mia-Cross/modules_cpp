#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {
    std::cout << "A random intern says hi, but nobody seems to respond\n";
    srand(time(NULL));
}
Intern::~Intern() {
    std::cout << "A random intern was fired, everyone already forgot his name\n";
}
Intern::Intern(Intern const &ref) {
    srand(time(NULL));
    (void)ref;
}
Intern &Intern::operator=(Intern const &ref) {
    (void)ref;
    return (*this);
}

Form *Intern::makeForm(std::string const &name, std::string const &target) const
{
    Form *(Intern::*create[4])(std::string const &, std::string const &) const
    = { &Intern::makePPF, &Intern::makeRRF, &Intern::makeSCF };
    Form *to_write;
    int i = 0;

    while (i < 4)
    {
        try {
            to_write = (this->*create[i])(name, target); }
        catch (ThatsIt) {
            break; }
        catch (UnknownFormException &e) {
            std::cout << e.what();
            return NULL; }
        catch (TryAgain) {
            i++; }
    }
    std::cout << "Intern creates " << to_write->getName() << "\n";
    return (to_write);
    // try
    // {
    //     try {
    //         to_write = new ShrubberyCreationForm(name, target);
    //     }
    //     catch (TryAgain)
    //     {
    //         std::cout << "It's not a SCF\t";
    //         try {
    //             to_write = new RobotomyRequestForm(target);
    //         }
    //         catch (TryAgain)
    //         {
    //             std::cout << "It's not a RRF\t";
    //             try {
    //                 to_write = new PresidentialPardonForm(target);
    //             }
    //             catch (TryAgain)
    //             {
    //                 std::cout << "It's not a PPF\t";
    //                 throw UnknownFormException();
    //             }
    //         }
    //     }
    // }
    // catch (UnknownFormException &e) {
    //     std::cout << "Failed to make form because : " << e.what() << "\n";
    //     return (NULL);
    // }

}

Form *Intern::makePPF(std::string const &name, std::string const &target) const  {
    Form *ppf = new PresidentialPardonForm(target);
    if (ppf->getName().compare(name))
        throw TryAgain();
    return(ppf);
  //  return(new PresidentialPardonForm(name, target));
}
Form *Intern::makeSCF(std::string const &name, std::string const &target) const  {
    Form *scf = new PresidentialPardonForm(target);
    if (scf->getName().compare(name))
        throw TryAgain();
    return(scf);
   // return(new ShrubberyCreationForm(name, target));
}
Form *Intern::makeRRF(std::string const &name, std::string const &target) const  {
    Form *rrf = new PresidentialPardonForm(target);
    if (rrf->getName().compare(name))
        throw TryAgain();
    return(rrf);
   // return(new RobotomyRequestForm(name, target));
}
Form *Intern::endOfTab(std::string const &name, std::string const &target) const {
    (void)name;
    (void)target;
    throw UnknownFormException();
    return (NULL);
}

// void Intern::initTab() {
//     this->create[0] = &makePPF;
//     this->create[1] = &makeRRF;
//     this->create[2] = &makeSCF;
//     this->create[3] = &endOfTab;
// }
