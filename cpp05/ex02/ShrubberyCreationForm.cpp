#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("S.C.F.", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
    Form("S.C.F.", 145, 137), target(target) {
        srand(time(NULL)); }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref) : 
    Form("S.C.F.", 145, 137), target(ref.target) {
    srand(time(NULL));
    *this = ref;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref) {
    (void)ref;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const {
    Form::execute(bureaucrat);
    int x = rand() % 5;
    x == 0 ? x = 1 : x;
    std::ofstream o(generateFileName().c_str());
    this->generateTrees(x, &o);
    std::cout << x << " trees have been planted in " << generateFileName() << "\n";
}

void ShrubberyCreationForm::generateTrees(int x, std::ofstream *o) const {
    int h = -1;
    while (h++ < 17)
    {
        int i = x + 1;
        while (--i)
            *o << tree[h];
        *o << std::endl;
    }
}

std::string const ShrubberyCreationForm::generateFileName() const {
    std::string str(this->target);
    str.append("_shrubbery");
    return (str); 
}
