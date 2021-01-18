/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:26:18 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/18 17:54:39 by lemarabe         ###   ########.fr       */
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
    Convert convert;
    try {
        Convert test(av[1]);
        convert = test;
        convert.displayChar();
        convert.displayInt();
        convert.displayFloat();
        convert.displayDouble();
    }
    catch (Convert::NonNumericValueToConvert) {
        convert.setValueAsChar(av[1][0]);
        convert.setValueAsInt(av[1][0]);
        convert.setValueAsFloat(av[1][0]);
        convert.setValueAsDouble(av[1][0]);
    }
    catch (Convert::NotANumberException) {
        convert.displayValuesForNAN();
    }
    catch (Convert::InfiniteException &e) {
        convert.displayValuesForInf(e.infSign(convert));
    }
}