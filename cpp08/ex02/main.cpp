/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 03:39:12 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/26 06:51:06 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main()
{
    MutantStack<int>    mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
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
    std::stack<int> s(mstack);
    mstack.displayValues();
    s.push(-8000);
    while (!s.empty())
    {
        std::cout << "[" << s.top() << "]  ";
        s.pop();
    }
    std::cout << std::endl << mstack.top() << std::endl;
    return 0;
}

