#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat best("judy", 1);
    Bureaucrat worst("ernest", 147);
    Form master("000A-00", 1);
    Form random("023C-98", 147);
    std::cout << std::endl;

    std::cout << best << worst << master << random << std::endl;

    try {
        worst.signForm(&random);}
    catch (std::exception &e) {
        std::cout << "Exception C caught ->\t" << e.what();}

    try {
        worst.signForm(&master);}
    catch (std::exception &e) {
        std::cout << "Exception A caught ->\t" << e.what();}

    try {
        best.signForm(&master);}
    catch (std::exception &e) {
        std::cout << "Exception B caught ->\t" << e.what();}
    

    try {
        Form zero("impossible", 0); }
    catch (std::exception &e) {
            std::cout << "Exception D caught ->\t" << e.what();}

    std::cout << std::endl;
    return 0;
}