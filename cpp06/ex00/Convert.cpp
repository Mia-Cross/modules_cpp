/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:26:11 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/16 22:45:09 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {}

Convert::~Convert() {}

Convert::Convert(const char *value) : valueAsCStr(value), valueAsString(value) {}

Convert::Convert(Convert const &ref) {*this = ref; }

Convert &Convert::operator=(Convert const &ref) {
    if (this != &ref)
    {
        this->valueAsCStr = ref.valueAsCStr;
        this->valueAsString = ref.valueAsString;
    }
    return (*this);
}

// ***************** GETTERS ***************** //

std::string const &Convert::getValueAsString() const {
    return (this->valueAsString);
}
char Convert::getValueAsChar() const {
    return(static_cast<char>(atof(this->valueAsCStr)));
}
int Convert::getValueAsInt() const {
    return (static_cast<int>(atof(this->valueAsCStr)));
}
float Convert::getValueAsFloat() const {
    return (static_cast<float>(atof(this->valueAsCStr)));
}
double Convert::getValueAsDouble() const {
    return (atof(this->valueAsCStr));
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