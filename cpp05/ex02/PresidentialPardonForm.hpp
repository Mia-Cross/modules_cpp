#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

# include "Form.hpp"

class PresidentialPardonForm : public virtual Form
{
    private:

        std::string const   target;
        PresidentialPardonForm();

    public:

        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &ref);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &ref) ;

        virtual bool execute(Bureaucrat const &bureaucrat) const;

        // std::string const	&getName() const;
        // int					getSignGrade() const;
        // bool				getSign() const;
		// bool				beSigned(Bureaucrat const *bureaucrat);
        // std::string const	introduce() const;

		// class GradeTooHighException : public std::exception {
        // 	public:
		// 		virtual const char *what() const throw() {
		// 			return ("Grade too high !\n");
		// 		}
        // };
		// class GradeTooLowException : public std::exception {
        // 	public:
		// 		virtual const char *what() const throw() {
		// 			return ("Grade too low !\n");
		// 		}
        // };
};

//std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &in);

#endif
