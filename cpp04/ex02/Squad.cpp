#include "Squad.hpp"

Squad::Squad() : count(0), first(NULL), last(NULL) {}

Squad::~Squad() {
    this->clearUnits();
}
Squad::Squad(Squad const &src) : count(0), first(NULL), last(NULL)
{
   // std::cout << "Copy called\n";
    for (int i = 0; i < src.getCount(); i++)
        push(src.getUnit(i)->clone());
}
Squad &Squad::operator=(Squad const &that)
{
    //std::cout << "Assignation called\n";
    if (this != &that)
    {
        this->clearUnits();
        for (int i = 0; i < that.getCount(); i++)
            push(that.getUnit(i)->clone());
    }
    return (*this);
}

int Squad::getCount() const {
    return (this->count);
}
// void Squad::setCount(int const count) {
//     this->count = count;
// }

ISpaceMarine    *Squad::getUnit(int index) const
{
    if (index >= this->count || index < 0)
    {
        std::cout << "No unit with index " << index << "\n";
        return (NULL);
    }

    t_list *elem = this->first;

    for (int i = 0; i < index; i++)
        elem = elem->next;
    return (elem->unit);
}

int Squad::push(ISpaceMarine *unit) 
{
    if (searchUnits(unit))
        return (this->count);

    t_list *to_add = new t_list;

    to_add->unit = unit;
    to_add->next = NULL;

    if (count == 0)
    {
        this->first = to_add;
        this->last = to_add;
    }
    else
    {
        this->last->next = to_add;
        this->last = this->last->next;
    }
    return (++this->count);
}

void Squad::clearUnits()
{
    t_list *elem = this->first;

    std::cout << "Clearing " << this->count << " units\n";
    for (int i = 0; i < this->count; i++)
    {
        delete elem->unit;
        t_list *to_del = elem;
        elem = elem->next;
        delete to_del;
    }
    delete elem;
   this->count = 0;
   this->first = NULL;
   this->last = NULL;
}

int Squad::searchUnits(ISpaceMarine *ptr)
{
    t_list *elem = this->first;

    for (int i = 0; i < this->count; i++)
    {
        if (elem->unit == ptr)
        {
            std::cout << "Unit already in squad\n";
            return (1);
        }
        elem = elem->next;
    }
    return (0);
}