/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 03:39:18 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/26 06:38:09 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template < typename T >
void MutantStack<T>::displayValues() const {
    std::cout << "{MutantStackContent} ";
    for (const_iterator it = myStack.begin(); it != myStack.end(); it++)
    {
        std::cout << "[" << *it << "]  ";
    }
    std::cout << std::endl;
}

// template < typename T >
// std::ostream &operator<<(std::ostream &out, MutantStack<T> const &in) {
//     out << in.introduce();
//     return (out);
// }