#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("R.R.F.", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
    Form("R.R.F.", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref) : 
    Form("R.R.F.", 72, 45), target(ref.target) {
    *this = ref;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &ref) {
    (void)ref;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const {
    Form::execute(bureaucrat);
    srand(time(NULL));
    std::cout << "* Zzzz ZzzZZZZZZZZZZzz Zzz *\n";
    if (rand() % 2)
        std::cout << this->target << " has been robotomized successfully." << std::endl;
    else
        std::cout << this->target << " has been really badly robotomized." << std::endl;
}