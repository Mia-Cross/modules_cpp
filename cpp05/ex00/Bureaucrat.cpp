#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string const &name, int const grade) : name(name), grade(grade) {
    std::cout << "{creation} " << this->name << ", grade " << this->grade << "\n";
    if (this->grade < 1)
        throw GradeTooHighException();
    else if (this->grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {
    std::cout << "{destruction} " << this->name << ", grade " << this->grade << "\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref) : name(ref.getName()){
    *this = ref;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &ref) {
    if (this != &ref)
        this->grade = ref.grade;
    return (*this);
}

// ***************** GETTERS ***************** //

std::string const &Bureaucrat::getName() const {
    return (this->name);
}
int Bureaucrat::getGrade() const {
    return (this->grade);
}

// ***************** FUNCTIONS ***************** //

void Bureaucrat::increaseGrade() {
    this->grade--;
    if (this->grade < 1)
        throw GradeTooHighException();
}
void Bureaucrat::decreaseGrade() {
    this->grade++;
    if (this->grade > 150)
        throw GradeTooLowException();
}

std::string const Bureaucrat::introduce() const {
    std::ostringstream oss;
    oss << this->name << ", bureaucrat grade ";
    oss << this->grade << std::endl;
    return (oss.str());
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &in) {
    out << in.introduce();
    return (out);
}