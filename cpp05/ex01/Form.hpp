#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:

        std::string const	name;
        bool				sign;
        int const			reqGrade;
        Form();

    public:

        ~Form();
        Form(std::string const &name, int const reqGrade);
        Form(Form const &ref);
        Form &operator=(Form const &ref) ;

        std::string const	&getName() const;
        int					getReqGrade() const;
        bool				getSign() const;
		bool				beSigned(Bureaucrat const *bureaucrat);
        std::string const	introduce() const;

		class GradeTooHighException : public std::exception {
        	public:
				virtual const char *what() const throw() {
					return ("Grade too high !\n");
				}
        };
		class GradeTooLowException : public std::exception {
        	public:
				virtual const char *what() const throw() {
					return ("Grade too low !\n");
				}
        };
};

std::ostream &operator<<(std::ostream &out, Form const &in);

#endif
