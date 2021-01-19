/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 04:03:31 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/19 04:50:56 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template < typename T >
T   max(T const &x, T const &y) {
    return ( x > y ? x : y);
}
template < typename T >
T   min(T const &x, T const &y) {
    return ( x < y ? x : y);
}
template < typename T >
void   swap(T &x, T &y) {
    T z = x;
    x = y;
    y = z;
}