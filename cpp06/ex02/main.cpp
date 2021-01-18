/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:39:33 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/18 05:02:50 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

int main() 
{
    A *a = new A;
    B *b = new B;
    C *c = new C;
    srand(time(NULL));
    
    std::cout << "Identifying A, B & C from pointers :\n";
    identify_from_pointer(a);
    identify_from_pointer(b);
    identify_from_pointer(c);

    std::cout << "Identifying A, B & C from references :\n";
    identify_from_reference(*a);
    identify_from_reference(*b);
    identify_from_reference(*c);
    
    std::cout << "Identifying an object returned by generate() :\n";
    Base *random_ptr = generate();
    Base &random_ref = *random_ptr;
    std::cout << "By pointer\t";
    identify_from_pointer(random_ptr);
    std::cout << "By reference\t";
    identify_from_reference(random_ref);

    delete random_ptr;
    delete a;
    delete b;
    delete c;
}