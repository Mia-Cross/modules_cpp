/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:11:33 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/26 03:29:34 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include "cstdlib"

int main()
{
    std::cout << "* SIMPLE TESTS *\n\n";
    
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    sp.display();
    std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span : " << sp.longestSpan() << std::endl;
    
    try {
        sp.addNumber(34);
    } catch (std::exception &e) {
        std::cout << e.what();
    }

    std::cout << "\n* WITH RANDOM NUMBERS *\n\n";

    srand(time(NULL));
    Span random = Span(10);
    for (int i = 10; i; i--)
        random.addNumber(rand());
    random.display();
    std::cout << "Shortest span : " << random.shortestSpan() << std::endl;
    std::cout << "Longest span : " << random.longestSpan() << std::endl;

    std::cout << "\n* WITH LARGE SPAN *\n\n";

    std::vector<int> vect;
    for (int i = 1; i < 10; i++) { vect.push_back(i); }         //adds 9 elements
    for (int i = 1; i < 10; i++) { vect.push_back(-i); }        //total : 9->18
    for (int i = 1; i < 10; i++) { vect.push_back(i*10); }      //total : 18->27
    for (int i = 1; i < 10; i++) { vect.push_back(-i*10); }     //total : 27->36
    for (int i = 1; i < 10; i++) { vect.push_back(i*303); }     //total : 36->45
    for (int i = 1; i < 10; i++) { vect.push_back(-i*8008); }   //total : 45->54
    for (int i = 1; i < 10; i++) { vect.push_back(i*27); }      //total : 54->63
    for (int i = 1; i < 10; i++) { vect.push_back(-i*13); }     //total : 63->72
    for (int i = 1; i < 10; i++) { vect.push_back(i*36000); }   //total : 72->81
    for (int i = 1; i < 10; i++) { vect.push_back(-i*1000000); }//total : 81->90
    for (int i = 1; i < 10; i++) { vect.push_back(i*456); }     //total : 90->99
    for (int i = 0; i < 10; i++) { vect.push_back(i*0); }       //total : 99->109

    Span xxl(100);
    try {
        xxl.addNumber(vect.begin(), vect.end());
    } catch (std::exception &e) {
        std::cout << e.what();
    }
    xxl.display();
    std::cout << "Shortest span : " << xxl.shortestSpan() << std::endl;
    std::cout << "Longest span : " << xxl.longestSpan() << std::endl;
}
