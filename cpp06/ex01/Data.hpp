/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:10:26 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/18 04:10:50 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <cstdlib>
# include <iostream>

class Data {

    public:

        Data();
        ~Data();
        Data(Data const &ref);
        Data &operator=(Data const &ref);

        std::string const   &getStr1();
        int                 getInt();
        std::string const   &getStr2();
        void                setStr1(std::string const);
        void                setInt(int);
        void                setStr2(std::string const);

    private:

        std::string s1;
        int         n;
        std::string s2;
};

#endif