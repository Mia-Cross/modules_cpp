/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 04:03:34 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/19 04:51:26 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main()
{
    int i1(-999), i2(777);
    float f1(42.0), f2(42.1), f3(42.0);
    char c1('2'), c2('<');
    std::string str = "chaine 1";
    const char *s1 = str.c_str();
    std::string str2 = "chaine 2";
    const char *s2 = str2.c_str();

    std::cout << "MAX BETWEEN INTS : " << ::max(i1, i2) << std::endl;
    std::cout << "MAX BETWEEN FLOATS : " << ::max(f1, f2) << std::endl;
    std::cout << "MAX BETWEEN EQUAL FLOATS : " << ::max(f1, f3) << std::endl;
    std::cout << "MAX BETWEEN CHARACTERS : " << ::max(c1, c2) << std::endl;
    std::cout << "MAX BETWEEN STRINGS : " << ::max(s1, s2) << std::endl;
    std::cout << std::endl;

    std::cout << "MIN BETWEEN INTS : " << ::min(i1, i2) << std::endl;
    std::cout << "MIN BETWEEN FLOATS : " << ::min(f1, f2) << std::endl;
    std::cout << "MIN BETWEEN EQUAL FLOATS : " << ::min(f1, f3) << std::endl;
    std::cout << "MIN BETWEEN CHARACTERS : " << ::min(c1, c2) << std::endl;
    std::cout << "MIN BETWEEN STRINGS : " << ::min(s1, s2) << std::endl;
    std::cout << std::endl;

    std::cout << "SWAP BETWEEN INTS :" << std::endl;
    std::cout << "-> before :\tI1 = " << i1 << ", I2 = " << i2 << "\n";
    ::swap(i1, i2);
    std::cout << "-> after :\tI1 = " << i1 << ", I2 = " << i2 << "\n";
    std::cout << "SWAP BETWEEN FLOATS : " << std::endl;
    std::cout << "-> before :\tF1 = " << f1 << ", F2 = " << f2 << "\n";
    ::swap(f1, f2);
    std::cout << "-> after :\tF1 = " << f1 << ", F2 = " << f2 << "\n";
    std::cout << "SWAP BETWEEN CHARACTERS : " << std::endl;
    std::cout << "-> before :\tC1 = " << c1 << ", C2 = " << c2 << "\n";
    ::swap(c1, c2);
    std::cout << "-> after :\tC1 = " << c1 << ", C2 = " << c2 << "\n";
    std::cout << "SWAP BETWEEN STRINGS : " << std::endl;
    std::cout << "-> before :\tS1 = " << s1 << ", S2 = " << s2 << "\n";
    ::swap(s1, s2);
    std::cout << "-> after :\tS1 = " << s1 << ", S2 = " << s2 << "\n";

    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}