/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 03:39:15 by lemarabe          #+#    #+#             */
/*   Updated: 2021/01/26 07:05:27 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H
# define MUTANT_STACK_H

# include <iostream>
# include <sstream>
# include <stack>
# include <deque>
# include <iterator>

template < typename T >
class MutantStack : public std::stack< T >
{
    public:

        typedef typename std::deque<T>::iterator         iterator;
        typedef typename std::deque<T>::const_iterator   const_iterator;

        typename std::deque<T>::iterator        begin() { return (myStack.begin()); }
        typename std::deque<T>::iterator        end() { return (myStack.end()); }
        typename std::deque<T>::const_iterator  begin() const { return (myStack.begin()); }
        typename std::deque<T>::const_iterator  end() const { return (myStack.end()); }
        
        MutantStack() : container_type((std::deque<T>)), size_type(size_t) {}
        virtual ~MutantStack() {}
        MutantStack(MutantStack const &ref) { *this = ref; }
        MutantStack &operator=(MutantStack const &ref) {
            if (this != &ref)
            {
                this->myStack.clear();
                for (MutantStack::const_iterator it = ref.begin(); it != ref.end(); it++)
                    this->myStack.push_back(it);
            }
        }

        void    push(T to_add)  { myStack.push_front(to_add); }
        T       &top()          { return (myStack.front()); }
        T const &top() const    { return (myStack.front()); }
        void    pop()           { myStack.pop_front(); }
        size_t  size() const    { return (myStack.size()); }

        void    displayValues() const {
            std::cout << "{MutantStackContent} ";
            for (const_iterator it = myStack.begin(); it != myStack.end(); it++)
            {
                std::cout << "[" << *it << "]  ";
            }
            std::cout << std::endl;
        }

    private:

        std::deque<T> myStack;
};

// template < typename T >
// std::stack<T>(MutantStack::MutantStack<T> const &ref)

// template < typename T >
// std::ostream &operator<<(std::ostream &out, MutantStack<T> const &in);

#endif
