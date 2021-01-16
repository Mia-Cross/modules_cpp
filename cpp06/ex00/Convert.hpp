/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:26:07 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/16 22:34:56 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include <iostream>
# include <sstream>
# include <stdlib.h>

class Convert
{
    private:
        const char *valueAsCStr;
        std::string valueAsString;
        Convert();

    public:

        ~Convert(); //virtual?
        Convert(const char *valueAsCStr);
        Convert(Convert const &ref);
        Convert &operator=(Convert const &ref);

        std::string const   &getValueAsString() const;
        char                getValueAsChar() const;
        int                 getValueAsInt() const;
        float               getValueAsFloat() const;
        double              getValueAsDouble() const;

        std::string const   introduce() const;
};

std::ostream &operator<<(std::ostream &out, Convert const &in);

#endif
