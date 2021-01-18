/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:11:03 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/18 04:11:04 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {}
Data::~Data() {}
Data::Data(Data const &ref) { (void)ref; }
Data &Data::operator=(Data const &ref) { (void)ref; return *this; }

std::string const &Data::getStr1() {
    return (this->s1);
}
int Data::getInt() {
    return (this->n);
}
std::string const &Data::getStr2() {
    return (this->s2);
}
void Data::setStr1(std::string const s1) {
    this->s1 = s1;
}
void Data::setInt(int n) {
    this->n = n;
}
void Data::setStr2(std::string const s2) {
    this->s2 = s2;
}

