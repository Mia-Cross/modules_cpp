#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("P.P.F.", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
    Form("P.P.F.", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref) : 
    Form("P.P.F.", 25, 5), target(ref.target) {
    *this = ref;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &ref) {
    (void)ref;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const {
    Form::execute(bureaucrat);
    std::cout << this->target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}