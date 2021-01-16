#ifndef CLASS_NAME_H
# define CLASS_NAME_H

# include <iostream>
# include <sstream>

class X_CLASS
{
    private:
        std::string X_STR;
        unsigned int X_INT;

    public:

        X_CLASS();
        ~X_CLASS(); //virtual?
        X_CLASS(std::string const &X_STR, int const X_INT);
        X_CLASS(X_CLASS const &ref);
        X_CLASS &operator=(X_CLASS const &ref);

        std::string const &getX_STR() const;
        int getX_INT() const;
        void setX_STR(std::string const &X_STR);
        void setX_INT(int X_INT);

        virtual void method() const = 0;
        virtual void virtualFunction();
        std::string const introduce() const;
};

std::ostream &operator<<(std::ostream &out, X_CLASS const &in);

#endif
