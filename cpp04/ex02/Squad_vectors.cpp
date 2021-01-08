#include "Squad.hpp"

Squad::Squad() {}

Squad::~Squad() {
    this->clearUnits();
}

Squad::Squad(Squad const &src) {
    *this = src; }

Squad &Squad::operator=(Squad const &that) {    
    if (this != &that)
    {
        this->clearUnits();
        for (unsigned int i = 0; i < that.units.size(); i++)
            this->units.push_back(that.units[i]);
    }
    return (*this);
}

int Squad::getCount() const {
    return (this->units.size());
}

ISpaceMarine    *Squad::getUnit(int index) const {
    if (index >= (int)this->units.size() || index < 0)
    {
        std::cout << "No unit with index " << index << "\n";
        return (NULL);
    }
    return (units[index]);
}
int Squad::push(ISpaceMarine *unit) {
    this->units.push_back(unit);
    return (this->units.size());
}

void Squad::clearUnits() {
    for (unsigned int i = 0; i < this->units.size(); i++)
        delete this->units[i];
    this->units.clear();
}