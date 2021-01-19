/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:26:18 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/19 01:03:03 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int ac, char **av)
{
    switch (ac)
    {
        case 2:
            break;
        case 1:
            std::cerr << "Please give me a value to convert\n";
            return (1);
        default:
            std::cerr << "I can only convert 1 value at a time\n";
            return (1);
    }
    Convert convert(av[1]);
    convert.displayChar();
    convert.displayInt();
    convert.displayFloat();
    convert.displayDouble();
}