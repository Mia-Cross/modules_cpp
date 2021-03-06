/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 06:20:51 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/24 18:44:29 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    const std::string strArray[3] = { "hi", "it's", "me" };
    const int intArray[7] = { 123, 4567, 890, -312, -56, 43, 2111000 };
    const float floatArray[3] = { 23.12, 34.32, 90.3 };
   // int *n = NULL;
    
    ::iter(strArray, 3, ::readContent);
    std::cout << std::endl;
    ::iter(strArray, 3, ::displayAddr);
    std::cout << std::endl;
    ::iter(intArray, 7, ::readContent);
    std::cout << std::endl;
    ::iter(intArray, 7, ::displayAddr);
    std::cout << std::endl;
    ::iter(floatArray, 3, ::readContent);
    std::cout << std::endl;
    ::iter(floatArray, 3, ::displayAddr);
    std::cout << std::endl;
}