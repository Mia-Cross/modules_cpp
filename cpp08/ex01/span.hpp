#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <sstream>
# include <vector>
# include <algorithm>
# include <iterator>

typedef std::vector<int>::const_iterator    vectConstIter;

class Span
{
    private:

        unsigned int        maxSize;
        std::vector<int>    storage;
        Span();

    public:

        Span(unsigned int size);
        ~Span();
        Span(Span const &ref);
        Span &operator=(Span const &ref);

        virtual void    addNumber(int);
        virtual void    addNumber(vectConstIter, vectConstIter);
        unsigned int    shortestSpan() const ;
        unsigned int    longestSpan() const;
        void            display() const;

        struct FullContainerException : public std::exception {
            const char * what() const throw() {
                return ("Can't add any more numbers\n");
            }
        };
        struct EmptyContainerException : public std::exception {
            const char * what() const throw() {
                return ("Not enough numbers to compare\n");
            }
        };
};

#endif
