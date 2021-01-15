#ifndef INTERN_H
# define INTERN_H

# include "Form.hpp"

class Form;

class Intern
{
    public:

        Intern();
        ~Intern();
        Intern(Intern const &ref);
        Intern &operator=(Intern const &ref) ;

        Form *makeForm(std::string const &name, std::string const &target) const;

        class ThatsIt : public std::exception {
            public:
				virtual const char *what() const throw() {
					return (NULL);
				}
        };
		class UnknownFormException : public std::exception {
        	public:
				virtual const char *what() const throw() {
					return ("Intern does know how to write this form, let's fire him!\n");
				}
        };
        class TryAgain : public std::exception {
        	public:
				virtual const char *what() const throw() {
					return ("It was not the right form type, try again!\n");
				}
        };

    private :
        Form *makePPF(std::string const &name, std::string const &target) const ;
        Form *makeRRF(std::string const &name, std::string const &target) const ;
        Form *makeSCF(std::string const &name, std::string const &target) const ;
        Form *endOfTab(std::string const &name, std::string const &target) const ;
     //   void initTab();
};

#endif
