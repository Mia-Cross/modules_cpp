#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

# include "Form.hpp"
# include <cstdlib>

class RobotomyRequestForm : public Form
{
    private:

        std::string const   target;
        RobotomyRequestForm();

    public:

        virtual ~RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &ref);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &ref) ;

        virtual void execute(Bureaucrat const &bureaucrat) const;
};

#endif
