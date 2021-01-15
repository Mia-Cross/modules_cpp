#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

# include <cstdlib>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:

        std::string const   target;
        RobotomyRequestForm();

    public:

        virtual ~RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(std::string const &name, std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &ref);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &ref) ;

        virtual void execute(Bureaucrat const &bureaucrat) const;
};

#endif
