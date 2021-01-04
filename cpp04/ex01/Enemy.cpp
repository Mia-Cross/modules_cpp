#include "Enemy.hpp"
#include <unistd.h>

Enemy::Enemy() {}

Enemy::Enemy(int hp, std::string const &type) : hp(hp), type(type) {
    std::cout << "Enemy \"" << type << "\" appeared.\n";
}

Enemy::Enemy(Enemy const &src) {
    *this = src;
}

Enemy &Enemy::operator=(Enemy const &that) {
    if (this != &that)
    {
        this->type = that.getType();
        this->hp = that.getHP();
    }
    return (*this);
}

Enemy::~Enemy() {
    std::cout << "Enemy \"" << type << "\" is dead.\n";
}

std::string Enemy::getType() const {
    return (this->type);
}
int Enemy::getHP() const {
    return (this->hp);
}
void Enemy::setType(std::string type) {
    this->type = type;
}
void Enemy::setHP(int hp) {
    this->hp = hp;
}

void Enemy::takeDamage(int damage) {
    //write(1, "&", 1);
    if (this->getHP() > 0)
    {
        this->setHP(this->getHP() - damage);
        if (this->getHP() < 0)
            this->setHP(0);
    }
}