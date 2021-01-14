#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:

        std::string const	name;
        bool				sign;
        int const			signGrade;
        int const			execGrade;
        Form();

    public:

        virtual ~Form();
        Form(std::string const &name, int const signGrade, int const execGrade);
        Form(Form const &ref);
        Form &operator=(Form const &ref) ;

        std::string const	&getName() const;
        bool				getSignedStatus() const;
        int					getSignGrade() const;
        int					getExecGrade() const;
		bool				beSigned(Bureaucrat const &bureaucrat);
        virtual void        execute(Bureaucrat const &bureaucrat) const;
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
        class FormedNotSigned : public std::exception {
        	public:
				virtual const char *what() const throw() {
					return ("Form is not signed !\n");
				}
        };
};

std::ostream &operator<<(std::ostream &out, Form const &in);

#endif
