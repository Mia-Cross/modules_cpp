/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:40:00 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/18 05:03:30 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

Base *generate() 
{
    Base *base;
    int x = rand();

    switch (x % 3)
    {
        case 0:
            base = new A;
            break;
        case 1:
            base = new B;
            break;
        case 2:
            base = new C;
            break;
    }
    return (base);
}

void identify_from_pointer(Base *p)
{
    A* aptr = dynamic_cast<A*>(p);

    if (aptr != NULL)
        std::cout << "-> Type A\n";
    else
    {
        B* bptr = dynamic_cast<B*>(p);

        if (bptr != NULL)
            std::cout << "-> Type B\n";
        else
        {
            C* cptr = dynamic_cast<C*>(p);

            if (cptr != NULL)
                std::cout << "-> Type C\n";
            else
                std::cout << "Pointer is neither A, B, nor C.\n";
        }
    }
}

void identify_from_reference(Base &r)
{
    try {
        A aObject = dynamic_cast<A &>(r);
        std::cout << "-> Type A\n";
    }
    catch (std::exception &e)
    {
        try {
            B bObject = dynamic_cast<B &>(r);
            std::cout << "-> Type B\n";
        }
        catch (std::exception &e)
        {
            try {
                C cObject = dynamic_cast<C &>(r);
                std::cout << "-> Type C\n";
            }
            catch (std::exception &e)
            {
                std::cout << "Reference is neither A, B, nor C.\n";
            }
        }
    }
}

