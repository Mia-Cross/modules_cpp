/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 03:34:22 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/21 05:39:48 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <exception>

class CantFindException : public std::exception
{
    public:
        const char * what() const throw() {
            return ("Can't find given value\n");
        }
};

template < typename T >
typename T::const_iterator easyfind(T const &container, int to_find){
    typename T::const_iterator it;
    // typename T::const_iterator ite = container.end();
    // for (it = container.begin(); it != ite ; it++) {
    //     if (*it == to_find)
    //         return (it);
    // }
    it = container.find(to_find);
    throw CantFindException();
}


