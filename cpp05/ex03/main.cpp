#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
    Bureaucrat best("judy", 1);
    Bureaucrat worst("ernest", 140);
    Intern intern;
    std::cout << std::endl;

    Form *ppf = intern.makeForm("P.P.F.", "Arthur Dent");
    Form *rrf = intern.makeForm("R.R.F.", "Marvin the Paranoid");
    Form *scf = intern.makeForm("S.C.F.", "Slatibarfast");
    Form *error = intern.makeForm("unknown type", "");
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

    delete ppf;
    delete rrf;
    delete scf;
    delete error;

    return 0;
}