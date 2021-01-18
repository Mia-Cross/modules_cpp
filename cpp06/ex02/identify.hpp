/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:41:06 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/18 04:45:09 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_H
# define IDENTIFY_H

# include <cstdlib>
# include <iostream>

class Base {
    public:
        virtual ~Base() {};
};
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate();
void identify_from_pointer(Base *p);
void identify_from_reference(Base &r);

#endif