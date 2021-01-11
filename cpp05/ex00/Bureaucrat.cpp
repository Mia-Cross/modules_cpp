#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "{creation}" << this->name << this->grade << "\n";
}

Bureaucrat::~Bureaucrat() {
    std::cout << "{destruction}" << this->name << this->grade << "\n";
}

Bureaucrat::Bureaucrat(std::string const &name, int const grade) : name(name), grade(grade) {
    std::cout << "{creation}" << this->name << this->grade << "\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref) {
    *this = ref;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &ref) {
    if (this != &ref)
    {
        //this->name = ref.name;
        this->grade = ref.grade;
    }
    return (*this);
}

// ***************** GETTERS ***************** //

std::string const &Bureaucrat::getname() {
    return (this->name);
}
int Bureaucrat::getgrade() const {
    return (this->grade);
}

// ***************** SETTERS ***************** //

// void Bureaucrat::setname(std::string const &name) {
//     this->name = name;
// }
// void Bureaucrat::setgrade(int grade) {
//     this->grade = grade;
// }

// ***************** FUNCTIONS ***************** //

std::string const &Bureaucrat::introduce() const {
    std::string intro = "{introduction} ";
    intro += (this->name + "\n");
    return (intro);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &in) {
    out << in.introduce();
    return (out);
}