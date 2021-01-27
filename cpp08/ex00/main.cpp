/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 03:34:24 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/27 18:42:53 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>
#include <list>
#include <deque>

int main()
{
    std::cout << ">> INT VECTOR\n";
    std::vector<int> intVector;
    for (int i = 1; i < 13; i++) { intVector.push_back(i * 10); };
    try {
    std::cout << *(::easyfind(intVector, 100)) << std::endl;
    std::cout << *(::easyfind(intVector, 42)) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what();
    }
    
    std::cout << ">> INT VECTOR CONST\n";
    std::vector<int> const constVector(12, 42);
    try {
    std::cout << *(::easyfind(constVector, 42)) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what();
    }

    std::cout << ">> CHAR VECTOR\n";
    std::vector<char> charVector;
    charVector.push_back('c');
    charVector.push_back('h');
    charVector.push_back('a');
    charVector.push_back('r');
    charVector.push_back('*');
    try {
    std::cout << *(::easyfind(charVector, 42)) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what();
    }

    std::cout << ">> INT SET\n";
    std::set<int> intSet;
    for (int i = 1; i < 5; i++) { intSet.insert(-i); };
    try {
    std::cout << *(::easyfind(intSet, -4)) << std::endl;
    std::cout << *(::easyfind(intSet, -12)) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what();
    }
        
    std::cout << ">> INT DOUBLE-ENDED QUEUE\n";
    std::deque<int> intDeque;
    for (int i = 1; i < 5; i++) { intDeque.push_back(i + 1); };
    try {
    std::cout << *(::easyfind(intDeque, 5)) << std::endl;
    std::cout << *(::easyfind(intDeque, 0)) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what();
    }

    std::cout << ">> INT LIST\n";
    std::list<int> intList;
    for (int i = 1; i < 5; i++) { intList.push_back(i + 1); };
    try {
    std::cout << *(::easyfind(intList, 5)) << std::endl;
    std::cout << *(::easyfind(intList, 0)) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what();
    }
}