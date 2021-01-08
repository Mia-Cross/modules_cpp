//#include "X_CLASS.hpp"
#include "template.hpp"

X_CLASS::X_CLASS() {
    std::cout << "{creation}" << this->X_STR << this->X_INT << "\n";
}

X_CLASS::~X_CLASS() {
    std::cout << "{destruction}" << this->X_STR << this->X_INT << "\n";
}

X_CLASS::X_CLASS(std::string const &X_STR, int const X_INT) : X_STR(X_STR), X_INT(X_INT) {
    std::cout << "{creation}" << this->X_STR << this->X_INT << "\n";
}

X_CLASS::X_CLASS(X_CLASS const &ref) {
    *this = ref;
}

X_CLASS &X_CLASS::operator=(X_CLASS const &ref) {
    if (this != &ref)
    {
        this->X_STR = ref.X_STR;
        this->X_INT = ref.X_INT;
    }
    return (*this);
}

// ***************** GETTERS ***************** //

std::string const &X_CLASS::getX_STR() const {
    return (this->X_STR);
}
int X_CLASS::getX_INT() const {
    return (this->X_INT);
}

// ***************** SETTERS ***************** //

void X_CLASS::setX_STR(std::string const &X_STR) {
    this->X_STR = X_STR;
}
void X_CLASS::setX_INT(int X_INT) {
    this->X_INT = X_INT;
}

// ***************** FUNCTIONS ***************** //

void X_CLASS::introduce() const {
    std::cout << "{introduction}" << this->X_STR << this->X_INT << "\n";
}

std::ostream &operator<<(std::ostream &out, X_CLASS const &in) {
    out << in.introduce();
    return (out);
}