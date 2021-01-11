#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

class Bureaucrat
{
    private:
        std::string const name;
        int grade;

    public:

        Bureaucrat();
        ~Bureaucrat(); //virtual?
        Bureaucrat(std::string const &name, int const grade);
        Bureaucrat(Bureaucrat const &ref);
        Bureaucrat &operator=(Bureaucrat const &ref) ;

        std::string const &getname();
        int getgrade() const;
        void setname(std::string const &name);
        void setgrade(int grade);

      //  virtual void method() const = 0;
        virtual void virtualFunction();
        std::string const &introduce() const;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &in);

#endif
