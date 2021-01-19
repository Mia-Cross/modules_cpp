/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 06:20:42 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/19 06:42:49 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < typename T >
void    iter(T *arr, int size, void (*f)(T const &))
{
    for (int i = 0; i < size; i++)
        (*f)(arr[i]);
}

template < typename T >
void    readContent(T const &elem)
{
    std::cout << elem << "\t";
    //std::cout << elem << std::endl;
}

template < typename T >
void    displayAddr(T const &elem)
{
    std::cout << &elem << "\t";
    // std::cout << &elem << std::endl;
}