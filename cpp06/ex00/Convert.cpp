/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:26:11 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/19 03:16:47 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {}
Convert::~Convert() {}
Convert::Convert(Convert const &ref) {*this = ref; }
Convert &Convert::operator=(Convert const &ref) { (void)ref; return (*this); }

// ***************** PARSE INPUT ***************** //

Convert::Convert(const char *value) : valueAsCStr(value), valueAsString(value),
    d(0.0), inf(false), sign(true), nan(false)
{
    if (!this->valueAsString.compare(0, 3, "nan"))
        this->nan = true;
    else if (!this->valueAsString.compare(0, 3, "inf")
        || !this->valueAsString.compare(1, 3, "inf"))
    {
        this->inf = true;
        if (this->valueAsString[0] == '-')
            this->sign = false;
    }
    else if (!isdigit(*this->valueAsCStr) && !(this->valueAsString[0] == '-' && isdigit(this->valueAsString[1])))
    {
        if (this->valueAsString.size() > 1)
            std::cout << "Will only convert the first character\n";
        d = static_cast<double>(this->valueAsCStr[0]);
    }
    if (d == 0.0)
        d = atof(this->valueAsCStr);
}

// ***************** CHECK VALUES ***************** //

void Convert::testCharValue() const
{
    if (nan || inf || this->d > 255.0 || this->d < 0.0)
        throw ImpossibleConversion();
    if (this->d > 126.0 || this->d < 32.0)
        throw NonDisplayableChar();
}

void Convert::testIntValue() const
{
    if (nan || inf || this->d > 2147483647.0 || this->d < -2147483647.0)
        throw ImpossibleConversion();
}

void Convert::testFloatValue() const
{
    if (inf)
        throw InfiniteException();
    if (this->d > std::numeric_limits<float>::max()
        || this->d < -1 * std::numeric_limits<float>::max())
        throw ImpossibleConversion();
}

// ***************** DISPLAY ***************** //

void Convert::displayChar() const
{
    std::cout << "char: ";
    try {
        this->testCharValue();
        std::cout << static_cast<char>(this->d) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
}

void Convert::displayInt() const
{
    std::cout << "int: ";
    try {
        this->testIntValue();
        std::cout << static_cast<int>(this->d) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
}

void Convert::displayFloat() const
{
    std::cout << "float: ";
    try {
        this->testFloatValue();
        std::cout << std::fixed << std::setprecision(1)
        << static_cast<float>(this->d) << "f\n";
    }
    catch (std::exception &e) {
        if (InfiniteException *inf = dynamic_cast<InfiniteException *>(&e))
        {
            if (this->sign == false)
                std::cout << "-";
            std::cout << inf->what() << "f\n";
        }
        else
            std::cout << e.what();
    }
}

void Convert::displayDouble() const
{
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << this->d << "\n";
}