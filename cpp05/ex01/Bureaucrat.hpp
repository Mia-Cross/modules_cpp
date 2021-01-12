#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <sstream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:

        std::string const	name;
        int					grade;
        Bureaucrat();

    public:

        ~Bureaucrat();
        Bureaucrat(std::string const &name, int const grade);
        Bureaucrat(Bureaucrat const &ref);
        Bureaucrat &operator=(Bureaucrat const &ref) ;

        std::string const	&getName() const;
        int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
        void                signForm(Form *form) const;
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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &in);

#endif
