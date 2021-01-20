/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:10:24 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/20 00:05:50 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void *serialize()
{
    static const char   *pool = "abcdefghijklmnopqrstuvwxyz0123456789";
    char                *serie = new char[20];
    int                 *iPtr = reinterpret_cast<int *>(serie + 8);

    for (int i = 0; i < 8; i++)
        serie[i] = pool[rand() % 36];
    *iPtr = rand();
    for (int i = 12; i < 20; i++)
        serie[i] = pool[rand() % 36];
    return (static_cast<void *>(serie));
}

Data *deserialize(void *zone)
{
    Data    *data = new Data;
    char    buf[9] = "";
    char    *c_ptr = static_cast<char *>(zone);
    int     *i_ptr = reinterpret_cast<int *>(zone);

    for (int i = 0; i < 8; i++)
        buf[i] = c_ptr[i];
    data->setStr1(buf);
    data->setInt(*i_ptr);
    for (int i = 12; i < 20; i++)
        buf[i - 12] = c_ptr[i];
    data->setStr2(buf);
    return (data);
}

int main()
{
    srand(time(NULL));

    std::cout << "Initializing a random sequence...\n";
    void *zone = serialize();

    std::cout << "Reading sequence in Data structure :\n";
    Data *data = deserialize(zone);
    std::cout << "Str1 =\t|" << data->getStr1() << "|\n";
    std::cout << "Int =\t|" << data->getInt() << "|\n";
    std::cout << "Str2 =\t|" << data->getStr2() << "|\n";

    delete data;
    int *i_ptr = reinterpret_cast<int*>(zone);
    delete [] i_ptr;
}