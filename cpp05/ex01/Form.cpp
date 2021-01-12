#include "Form.hpp"

Form::Form() : name(""), sign(false), reqGrade(0) {}

Form::Form(std::string const &name, int const reqGrade) : name(name), sign(false), reqGrade(reqGrade) {
    std::cout << "{creation} " << this->name << ", required grade " << this->reqGrade << "\n";
    if (this->reqGrade < 1)
        throw GradeTooHighException();
    else if (this->reqGrade > 150)
        throw GradeTooLowException();
}

Form::~Form() {
    std::cout << "{destruction} " << this->name << ", required grade " << this->reqGrade << "\n";
}

Form::Form(Form const &ref) : name(ref.name), sign(ref.sign), reqGrade(ref.reqGrade) {
    *this = ref;
}

Form &Form::operator=(Form const &ref) {
    if (this != &ref)
        this->sign = ref.sign;
    return (*this);
}

// ***************** GETTERS ***************** //

std::string const &Form::getName() const {
    return (this->name);
}
int  Form::getReqGrade() const {
    return (this->reqGrade);
}
bool Form::getSign() const {
    return (this->sign);
}

bool Form::beSigned(Bureaucrat const *bureaucrat) {
    if (this->sign == true)
        return (false);
    if (this->reqGrade < bureaucrat->getGrade())
        throw GradeTooLowException();
    else
        this->sign = true;
    return (this->sign);
}

std::string const Form::introduce() const {
    std::ostringstream oss;
    oss << this->name << ", form with grade required "<< this->reqGrade;
    if (this->sign)
        oss << " is signed" << std::endl;
    else
        oss << " is not signed yet" << std::endl;
    return (oss.str());
}

std::ostream &operator<<(std::ostream &out, Form const &in) {
    out << in.introduce();
    return (out);
}