#include "Form.hpp"

Form::Form() : name(""), sign(false), signGrade(0), execGrade(0) {}

Form::Form(std::string const &name, int const signGrade, int const execGrade) :
    name(name), sign(false), signGrade(signGrade), execGrade(execGrade) {
    std::cout << "{creation} " << this->name << ", requires grade " << this->signGrade;
    std::cout << " to sign, grade " << this->execGrade << " to execute\n";
    if (this->signGrade < 1)
        throw GradeTooHighException();
    else if (this->signGrade > 150)
        throw GradeTooLowException();
}

Form::~Form() {
    std::cout << "{destruction} " << this->name << ", required grade " << this->signGrade;
    std::cout << " to sign, grade " << this->execGrade << " to execute\n";
}

Form::Form(Form const &ref) :
    name(ref.name), sign(ref.sign), signGrade(ref.signGrade), execGrade(ref.execGrade) {
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
bool Form::getSignedStatus() const {
    return (this->sign);
}
int  Form::getSignGrade() const {
    return (this->signGrade);
}
int  Form::getExecGrade() const {
    return (this->execGrade);
}

// ***************** FUNCTIONS ***************** //

bool Form::beSigned(Bureaucrat const *bureaucrat) {
    if (this->sign == true)
        return (false);
    if (this->signGrade < bureaucrat->getGrade())
        throw GradeTooLowException();
    else
        this->sign = true;
    return (this->sign);
}

bool Form::execute(Bureaucrat const &executor) const {
    if (this->sign == false)
        throw FormedNotSigned();
    else if (this->execGrade >= executor.getGrade())
        return (true);
    else
        throw GradeTooLowException();
    return (false);
}

std::string const Form::introduce() const {
    std::ostringstream oss;
    oss << this->name << ", form requiring grade "<< this->signGrade;
    oss << " to sign, grade " << this->execGrade << " to execute";
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