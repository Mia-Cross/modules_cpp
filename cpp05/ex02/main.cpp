#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
    Bureaucrat best("judy", 1);
    Bureaucrat worst("ernest", 140);
    Form *ppf = new PresidentialPardonForm("Arthur Dent");
    Form *rrf = new RobotomyRequestForm("Marvin the Paranoid");
    Form *scf = new ShrubberyCreationForm("Slatibarfast");
    Form *scf2 = new ShrubberyCreationForm("Ford_Prefect");
    std::cout << std::endl;

    std::cout << best << worst << *ppf << *rrf << *scf << std::endl;

    worst.signForm(*ppf);
    worst.executeForm(*ppf);
    best.executeForm(*ppf);
    best.signForm(*ppf);
    best.executeForm(*ppf);
    std::cout << std::endl;

    best.signForm(*rrf);
    worst.executeForm(*rrf);
    best.executeForm(*rrf);
    std::cout << std::endl;

    worst.signForm(*scf);
    worst.executeForm(*scf);
    best.executeForm(*scf);
    std::cout << std::endl;
    worst.signForm(*scf2);
    best.executeForm(*scf2);
    std::cout << std::endl;

    delete ppf;
    delete rrf;
    delete scf;
    delete scf2;

    return 0;
}