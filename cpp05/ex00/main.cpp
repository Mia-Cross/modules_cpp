#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat best("judy", 3);
    Bureaucrat worst("ernest", 147);

    while (best.getGrade() > 0)
    {
        try {
            best.increaseGrade();
            std::cout << best;
        }
        catch (std::exception &e) {
            std::cout << "Exception A caught ->\t" << e.what();
        }
    }
    while (worst.getGrade() <= 150)
    {
        try {
            worst.decreaseGrade();
            std::cout << worst;
        }
        catch (std::exception &e) {
            std::cout << "Exception B caught ->\t" << e.what();
        }
    }

    try {
        Bureaucrat impossible("mike", -9);
    }
    catch (std::exception &e) {
            std::cout << "Exception C caught ->\t" << e.what();
    }
}