/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:26:07 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/18 17:54:56 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include <iostream>
# include <iomanip>
# include <stdio.h>
# include <sstream>
# include <limits>
# include <stdlib.h>

class Convert
{
    private:
        const char *valueAsCStr;
        std::string valueAsString;
        char c;
        int i;
        float f;
        double d;

    public:

        Convert();
        ~Convert(); //virtual?
        Convert(const char *valueAsCStr);
        Convert(Convert const &ref);
        Convert &operator=(Convert const &ref);

        std::string const   &getValueAsString() const;
        void                setValueAsChar();
        void                setValueAsChar(char c);
        void                setValueAsInt();
        void                setValueAsInt(char c);
        void                setValueAsFloat();
        void                setValueAsFloat(char c);
        void                setValueAsDouble();
        void                setValueAsDouble(char c);
        void                displayValuesForNAN();
        void                displayValuesForInf(char c);
        void                displayChar() ;
        void                displayInt() ;
        void                displayFloat() ;
        void                displayDouble() ;

        std::string const   introduce() const;

        class ImpossibleConversion: public std::exception {
            public:
				virtual const char *what() const throw() {
					return ("Impossible\n");
				}
        };
        class NonDisplayableChar: public std::exception {
            public:
				virtual const char *what() const throw() {
					return ("Non Displayable\n");
				}
        };
        class NonNumericValueToConvert: public std::exception {
            public:
				virtual const char *what() const throw() {
					return ("Value to convert is not a number\n");
				}
        };
        class NotANumberException: public std::exception {};
        class InfiniteException: public std::exception {
            public :
                virtual char infSign(Convert &convert) const throw() {
                    return (convert.getValueAsString()[0]);
                }
        };

};

std::ostream &operator<<(std::ostream &out, Convert const &in);

#endif
