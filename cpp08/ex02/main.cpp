/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 03:39:12 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/27 18:39:45 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main()
{
    std::cout << "BASIC TESTS FROM THE SUBJECT\n\n";
    MutantStack<int>    mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "TOP = " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "SIZE = " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    mstack.displayValues();
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while(it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    mstack.displayValues();

    std::cout << "\nCOPY MUTANT_STACK TO STACK\n\n";
    std::stack<int> s(mstack);
    mstack.displayValues();
    s.push(-8000);
    while (!s.empty())
    {
        std::cout << "[" << s.top() << "]  ";
        s.pop();
    }
    std::cout << std::endl << mstack.top() << std::endl;

    std::cout << "\nMUTANT_STACK WITH CHARACTERS\n\n";
    MutantStack<char> msChar;
    msChar.push('a');
    msChar.push('b');
    msChar.push('c');
    msChar.push('d');
    std::cout << "TOP = " << msChar.top() << std::endl;
    std::cout << "SIZE = " << msChar.size() << std::endl;
    msChar.pop();
    msChar.push('D');
    msChar.displayValues();
    
    std::cout << "EMPTY()? = " << msChar.empty() << std::endl;
    std::cout << "\nDISPLAY SELECTED VALUES\n\n";
    std::cout << "BEGIN + 2 (3rd element) = " << *(msChar.begin() + 2);
    std::cout << "\nEND - 1 (last element) = " << *(msChar.end() - 1);
    std::cout << std::endl;

    std::cout << "\nTESTING ASSIGNATION\n\n";
    MutantStack<int> ms2;
    
    ms2.push(-1);
    ms2.push(90);
    ms2 = mstack;
    ms2.displayValues();

    std::cout << "\nMUTANT_STACK WITH POINTERS\n\n";
    MutantStack<const char *> msStr;
    std::string s1 = "test with ptrs";
    std::string s2 = "can i store a string ?";
    std::string s3 = "no way";
    std::string s4 = "probably yes";
    msStr.push(s1.c_str());
    msStr.push(s2.c_str());
    msStr.push(s3.c_str());
    std::cout << "TOP = " << msStr.top() << std::endl;
    std::cout << "SIZE = " << msStr.size() << std::endl;
    msStr.pop();
    msStr.push(s4.c_str());
    msStr.displayValues();

    // std::cout << "\nTESTING CONSTANT\n\n";
    // MutantStack<int const> msConst;
    // msConst.push(64);
    // msConst.push(65);
    // msConst.push(66);
    // std::cout << "TOP = " << msConst.top() << std::endl;
  //  msConst.top() = 12;
    
    return 0;
}

