#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:

        std::string const   target;
        PresidentialPardonForm();

    public:

        virtual ~PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &ref);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &ref) ;

        virtual void execute(Bureaucrat const &bureaucrat) const;
};

#endif
