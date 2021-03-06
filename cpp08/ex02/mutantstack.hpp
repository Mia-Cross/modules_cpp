/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 03:39:15 by lemarabe          #+#    #+#             */
/*   Updated: 2021/02/03 23:08:34 by lemarabe         ###   ########.fr       */
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
class MutantStack : public virtual std::stack< T >
{
    private:

        std::deque<T> myStack;

    public:

        typedef typename std::deque<T>::iterator         iterator;
        typedef typename std::deque<T>::const_iterator   const_iterator;

        iterator        begin() { return (myStack.begin()); }
        iterator        end() { return (myStack.end()); }
        const_iterator  begin() const { return (myStack.begin()); }
        const_iterator  end() const { return (myStack.end()); }
        
        MutantStack() {}
        virtual ~MutantStack() {}
        MutantStack(MutantStack const &ref) { *this = ref; }
        MutantStack &operator=(MutantStack const &ref) {
            if (this != &ref)
            {
                while (!this->empty())
                    this->pop();
                this->myStack.clear();
                for (MutantStack::const_iterator it = ref.begin(); it != ref.end(); it++)
                    this->myStack.push_back(*it);
            }
            return (*this);
        }

        void    push(T to_add) {
            myStack.push_front(to_add);
            std::stack<T>::push(to_add);
        }
        
        void    pop() {
            myStack.pop_front();
            std::stack<T>::pop();
        }

        void    displayValues() const {
            std::cout << "{MutantStackContent} ";
            for (const_iterator it = myStack.begin(); it != myStack.end(); it++)
                std::cout << "[" << *it << "]  ";
            std::cout << std::endl;
        }
};

#endif
