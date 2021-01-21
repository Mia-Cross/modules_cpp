/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 03:34:24 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/21 05:44:49 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <map>

int main()
{
    std::cout << ">> INT VECTOR\n";
    std::vector<int> intVector;
    for (int i = 1; i < 13; i++) { intVector.push_back(i * 10); };
    std::cout << *(::easyfind(intVector, 100)) << std::endl;
    std::cout << *(::easyfind(intVector, 42)) << std::endl;
    
    std::cout << ">> INT VECTOR CONST\n";
    std::vector<int> const constVector(12, 42);
    std::cout << *(::easyfind(constVector, 42)) << std::endl;

    std::cout << ">> CHAR VECTOR\n";
    std::vector<char> charVector;
    charVector.push_back('c');
    charVector.push_back('h');
    charVector.push_back('a');
    charVector.push_back('r');
    charVector.push_back('*');
    std::cout << *(::easyfind(charVector, 42)) << std::endl;

    std::cout << ">> INT MAP (an int paired with an other variable\n";
    std::map<int, std::string>  intMap;
    std::pair<int, std::string> result;
    intMap[3] = "first number";
    intMap[78] = "second number";
    intMap[-966] = "third number";
    result = *(::easyfind(intMap, -966));
    std::cout << "Found " << result.second << ", paired with " << result.first << std::endl;
}