#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("P.P.F.", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
    Form("P.P.F.", 25, 5), target(target) {
    // std::cout << "{creation} " << this->name << ", required grade " << this->signGrade << "\n";
    // if (this->signGrade < 1)
    //     throw GradeTooHighException();
    // else if (this->signGrade > 150)
    //     throw GradeTooLowException();
}

PresidentialPardonForm::~PresidentialPardonForm() {
    // std::cout << "{destruction} " << this->name << ", required grade " << this->signGrade << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref) : 
    Form("P.P.F.", 25, 5), target(ref.target) {
    *this = ref;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &ref) {
    // if (this != &ref)
    //     this->sign = ref.sign;
    (void)ref;
    return (*this);
}

bool PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const {
    if (Form::execute(bureaucrat))
    {
        std::cout << this->target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
        return (true);
    }
    return (false);
}

// ***************** GETTERS ***************** //

// std::string const &PresidentialPardonForm::getName() const {
//     return (this->name);
// }
// int  PresidentialPardonForm::getSignGrade() const {
//     return (this->signGrade);
// }
// bool PresidentialPardonForm::getSign() const {
//     return (this->sign);
// }

// bool PresidentialPardonForm::beSigned(Bureaucrat const *bureaucrat) {
//     if (this->sign == true)
//         return (false);
//     if (this->signGrade < bureaucrat->getGrade())
//         throw GradeTooLowException();
//     else
//         this->sign = true;
//     return (this->sign);
// }

// std::string const PresidentialPardonForm::introduce() const {
//     std::ostringstream oss;
//     oss << this->name << ", form with grade required "<< this->signGrade;
//     if (this->sign)
//         oss << " is signed" << std::endl;
//     else
//         oss << " is not signed yet" << std::endl;
//     return (oss.str());
// }

// std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &in) {
//     out << in.Form::introduce();
//     return (out);
// }