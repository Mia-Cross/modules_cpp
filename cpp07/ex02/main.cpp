/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 00:31:26 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/20 04:08:28 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<char> emptyArray;
    std::cout << "CREATION D'UN ARRAY VIDE\tAdresse {" << emptyArray << "}\n";
    std::cout << "Contenu :\t";
    emptyArray.displayContent();

    Array<int> intArray(5); 
    std::cout << "\nCREATION D'UN ARRAY D'INTS\tAdresse {" << intArray << "}\n";
    intArray[0] = 1;
    intArray[1] = 11;
    intArray[2] = 21;
    intArray[3] = 1211;
    intArray[4] = 111221;
    try { intArray[5] = 312211; } //out of bounds index
    catch (std::exception &e) { std::cout << e.what(); }
    std::cout << "Contenu :\t";
    intArray.displayContent();

    Array<char> charArray(5);
    std::cout << "\nCREATION D'UN ARRAY DE CHAR\tAdresse {" << charArray << "}\n";
    charArray[0] = 'H';
    charArray[1] = 'e';
    charArray[2] = 'l';
    charArray[3] = 'l';
    charArray[4] = 'o';
    std::cout << "Contenu :\t";
    charArray.displayContent();

    Array<char> copyArray(charArray);
    std::cout << "\nCOPIE DE L'ARRAY\t\tAdresse {" << copyArray << "}\n";
    emptyArray = charArray;
    std::cout << "ASSIGNATION SUR L'ARRAY VIDE\tAdresse {" << emptyArray << "}\n";
    std::cout << "-> Modification de l'original : o -> !\n";
    charArray[4] = '!';
    std::cout << "Contenu de l'original :\t";
    charArray.displayContent();
    std::cout << "Contenu de la copie :\t";
    copyArray.displayContent();
    std::cout << "Contenu de l'assigné :\t";
    emptyArray.displayContent();

    Array<float> floatArray(3);
    std::cout << "\nCREATION D'UN ARRAY DE FLOATS\tAdresse {" << floatArray << "}\n";
    floatArray[0] = 99.97;
    floatArray[1] = 47.902;
    floatArray[2] = 45090.3;
    std::cout << "Contenu :\t";
    floatArray.displayContent();

    Array<std::string> strArray(3);
    std::cout << "\nCREATION D'UN ARRAY DE STRING\tAdresse {" << strArray << "}\n";
    strArray[0] = "this is my first string";
    strArray[1] = "this is my second string";
    strArray[2] = "this is my third string";
    std::cout << "Contenu :\t";
    strArray.displayContent();
}