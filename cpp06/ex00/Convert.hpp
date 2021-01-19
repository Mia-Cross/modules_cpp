/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:26:07 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/19 02:53:25 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include <iostream>
# include <iomanip>
# include <limits>
# include <stdlib.h>

class Convert
{
    private:

        const char  *valueAsCStr;
        std::string valueAsString;
        double      d;
        bool        inf;
        bool        sign;
        bool        nan;

    public:

        Convert();
        ~Convert();
        Convert(const char *valueAsCStr);
        Convert(Convert const &ref);
        Convert &operator=(Convert const &ref);

        void        testCharValue() const;
        void        testIntValue() const;
        void        testFloatValue() const;
        void        testDoubleValue() const;
        void        displayChar() const;
        void        displayInt() const;
        void        displayFloat() const;
        void        displayDouble() const;

        class ImpossibleConversion: public std::exception {
            public:
				virtual const char *what() const throw() {
					return ("Impossible\n"); }
        };
        class NonDisplayableChar: public std::exception {
            public:
				virtual const char *what() const throw() {
					return ("Non Displayable\n"); }
        };
        class InfiniteException: public std::exception {
            public:
				virtual const char *what() const throw() {
					return ("inf"); }
        };
};

#endif
