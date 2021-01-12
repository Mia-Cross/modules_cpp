#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
    Bureaucrat best("judy", 1);
    Bureaucrat worst("ernest", 147);
    Form master("000A-00", 1, 150);
    Form random("023C-98", 147, 1);
    Form *ppt = new PresidentialPardonForm("Marvin the Paranoid");
    std::cout << std::endl;

    std::cout << best << worst << master << random << *ppt << std::endl;

    worst.signForm(*ppt);
    worst.executeForm(*ppt);
    best.executeForm(*ppt);
    best.signForm(*ppt);
    best.executeForm(*ppt);


    std::cout << std::endl;
    return 0;
}