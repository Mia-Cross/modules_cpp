#ifndef A_MATERIA_H
# define A_MATERIA_H

# include <iostream>
//# include <vector>
# include <cstring>

class ICharacter;

class AMateria
{
    private:
        std::string type;
        unsigned int _xp;
        AMateria();

    public:

        AMateria(std::string const &type);
        AMateria(AMateria const &ref);
        AMateria &operator=(AMateria const &ref);
        virtual ~AMateria();

        std::string const &getType() const;
        unsigned int getXP() const;
        void setType(std::string const &);
        void setXP(unsigned int);

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);
};

typedef struct s_list {
    AMateria *materia;
    s_list *next;
}               t_list;

#endif
