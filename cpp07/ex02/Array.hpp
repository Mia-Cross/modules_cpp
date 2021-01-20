/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 00:09:16 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/20 04:04:53 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < typename T >
class Array
{
    private:

        unsigned int    nbElem;
        T               *array;

    public:

        Array() : nbElem(0), array(NULL) {};

        Array(unsigned int n) : nbElem(n), array(new T[n]) {};

        ~Array() { this->clearArray(); };

        Array(Array const &ref) : nbElem(ref.size()) {
            this->array = new T[this->nbElem];
            for (unsigned int i = 0; i < this->nbElem; i++)
                this->array[i] = ref.array[i]; 
        };

        Array const &operator=(Array const &ref) {
            if (this != &ref)
            {
                this->clearArray();
                this->nbElem = ref.size();
                this->array = new T[this->nbElem];
                for (unsigned int i = 0; i < this->nbElem; i++)
                    this->array[i] = ref.array[i]; 
            }
            return (*this);
        };

        T &operator[](int i) const {
            if (i < 0 || i >= static_cast<int>(this->nbElem))
                throw OutOfBounds();
            return (this->array[i]);
        };

        unsigned int size() const { return this->nbElem; };

        void displayContent() const {
            if (!this->nbElem)
                std::cout << "<empty>";
            for (unsigned int i = 0; i < this->nbElem; i++)
                std::cout << "[" << i << "] " << this->array[i] << "\t";
            std::cout << std::endl;
        }

        void clearArray() {
            if (nbElem)
                delete [] array;
        }

        class OutOfBounds : public std::exception {
            public :
                virtual const char *what() const throw() {
                    return ("Index is out of bounds\n");
                }
        };
};

template < typename T >
std::ostream &operator<<(std::ostream &o, Array<T> &array) {
    o << &array;
    return (o);
}