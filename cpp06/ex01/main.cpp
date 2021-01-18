/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:10:24 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/18 04:10:25 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void *serialize()
{
    static const char *pool = "abcdefghijklmnopqrstuvwxyz0123456789";
    int *serie = new int[17];

    for (int i = 0; i < 8; i++)
        serie[i] = pool[rand() % 36];
    serie[8] = rand();
    for (int i = 9; i < 17; i++)
        serie[i] = pool[rand() % 36];
    return ((void *)serie);
}

Data *deserialize(void *zone)
{
    Data *data = new Data;
    char buf[9] = "";
    char *c_ptr;
    int *ptr = reinterpret_cast<int *>(zone);

    for (int i = 0; i < 8; i++)
    {
        c_ptr = reinterpret_cast<char *>(ptr++);
        buf[i] = *c_ptr;
    }
    data->setStr1(buf);
    data->setInt(*ptr++);
    for (int i = 9; i < 17; i++)
    {
        c_ptr = reinterpret_cast<char *>(ptr++);
        buf[i - 9] = *c_ptr;
    }
    data->setStr2(buf);
    return (data);
}

int main()
{
    srand(time(NULL));

    std::cout << "Initializing a random sequence...\n";
    void *ptr = serialize();

    std::cout << "Reading sequence in Data structure :\n";
    Data *data = deserialize(ptr);
    std::cout << "Str1 =\t|" << data->getStr1() << "|\n";
    std::cout << "Int =\t|" << data->getInt() << "|\n";
    std::cout << "Str2 =\t|" << data->getStr2() << "|\n";

    delete data;
    int *i_ptr = reinterpret_cast<int*>(ptr);
    delete [] i_ptr;
}