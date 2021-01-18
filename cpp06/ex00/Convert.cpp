/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:26:11 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/18 18:02:43 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {}
Convert::~Convert() {}
Convert::Convert(Convert const &ref) {*this = ref; }
Convert &Convert::operator=(Convert const &ref) {
    if (this != &ref)
    {
        this->valueAsCStr = ref.valueAsCStr;
        this->valueAsString = ref.valueAsString;
    }
    return (*this);
}
Convert::Convert(const char *value) : valueAsCStr(value), valueAsString(value) {
    if (!this->valueAsString.compare(0, 3, "nan"))
        throw NotANumberException();
    if (!this->valueAsString.compare(0, 3, "inf") || !this->valueAsString.compare(1, 3, "inf"))
        throw InfiniteException();
    if (isalpha(*this->valueAsCStr))
    {
        if (this->valueAsString.size() > 1)
            std::cout << "Will only convert the first character\n";
        throw NonNumericValueToConvert();
    }
}

// ***************** GETTERS ***************** //

std::string const &Convert::getValueAsString() const {
    return (this->valueAsString);
}

void Convert::setValueAsChar()
{
    int i = atoi(this->valueAsCStr);

    if (i > std::numeric_limits<unsigned char>::max() ||
        i < std::numeric_limits<unsigned char>::min())
        throw ImpossibleConversion();
    else if (i > 126 || i < 32)
        throw NonDisplayableChar();
    this->c = static_cast<char>(i);
}

void Convert::setValueAsInt() 
{
    long l = atol(this->valueAsCStr);

    if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
        throw ImpossibleConversion();
    this->i = atoi(this->valueAsCStr);
}

void Convert::setValueAsFloat() {

    double d = atof(this->valueAsCStr);

    if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
        throw ImpossibleConversion();
    this->f = static_cast<float>(d);
}

void Convert::setValueAsDouble() {
    this->d = atof(this->valueAsCStr);
}

// ************** HANDLE CONVERSION FROM CHAR ************** //

void Convert::setValueAsChar(char c) {
    this->c = c;
}
void Convert::setValueAsInt(char c) {
    this->i = atoi(&c);
}
void Convert::setValueAsFloat(char c) {
    double d = atof(&c);
    this->f = static_cast<float>(d);
}
void Convert::setValueAsDouble(char c) {
    this->d = atof(&c);
}

// ************** HANDLE LITTERALS ************** //

void Convert::displayValuesForNAN() {
    //std::cout << "char: ";
}

void Convert::displayValuesForInf(char c) {
    (void)c;
}

// ***************** DISPLAY ***************** //

void Convert::displayChar() {
    try {
        std::cout << "char: ";
        this->setValueAsChar();
        std::cout << c << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
}
void Convert::displayInt() {
    try {
        std::cout << "int: ";
        this->setValueAsInt();
        std::cout << i << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
}
void Convert::displayFloat() {
    try {
        std::cout << "float: ";
        this->setValueAsFloat();
        //std::cout << std::setw(2) << f << std::endl;
        printf("%.1ff\n", f);
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
}
void Convert::displayDouble() {
    try {
        std::cout << "double: ";
        this->setValueAsDouble();
        printf("%.1f\n", d);
       // std::cout << d << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
}

// ***************** FUNCTIONS ***************** //

std::string const Convert::introduce() const {
    std::ostringstream oss;
    oss << "{introduction}" << this->valueAsString << "\n";
    return (oss.str());
}

std::ostream &operator<<(std::ostream &out, Convert const &in) {
    out << in.introduce();
    return (out);
}