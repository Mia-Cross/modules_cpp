/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 03:34:22 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/25 23:41:05 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <algorithm>

struct CantFindException : public std::exception
{
    const char * what() const throw() {
        return ("Can't find given value\n"); }
};

template < typename T >
typename T::const_iterator easyfind(T const &container, int to_find){
    typename T::const_iterator it;
    it = std::find(container.begin(), container.end(), to_find);
    if (it == container.end())
        throw CantFindException();
    return (it);
}


