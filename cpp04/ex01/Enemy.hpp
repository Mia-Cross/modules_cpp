#ifndef ENEMY_H
# define ENEMY_H

# include <iostream>

class Enemy
{
    private:

        int hp;
        std::string type;
        Enemy();
    
    public:

        Enemy(int hp, std::string const &type);
        Enemy(Enemy const &src);
        Enemy &operator=(Enemy const &that);
        virtual ~Enemy();

        std::string getType() const;
        int getHP() const;
        void setType(std::string type);
        void setHP(int hp);

        virtual void takeDamage(int damage);
};

#endif