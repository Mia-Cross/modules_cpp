#include "span.hpp"

Span::Span() {}

Span::~Span() { this->storage.clear(); }

Span::Span(unsigned int size) : maxSize(size) {
    this->storage.reserve(size);
}
Span::Span(Span const &ref) {
    *this = ref;
}
Span &Span::operator=(Span const &ref) {
    if (this != &ref)
    {
        this->storage.clear();
        this->maxSize = ref.maxSize;
        for (vectConstIter itSrc = ref.storage.begin();
        itSrc != ref.storage.end(); itSrc++)
            this->storage.push_back(*itSrc);
    }
    return (*this);
}

void Span::addNumber(int x) {
    if (this->storage.size() >= this->maxSize)
        throw FullContainerException();
    this->storage.push_back(x);
}

 void Span::addNumber(vectConstIter begin, vectConstIter end) {
    while (begin != end)
    {
        if (this->storage.size() >= this->maxSize)
            throw FullContainerException();
        this->storage.push_back(*begin);
        begin++;
    }
}

unsigned int Span::shortestSpan() const {
    if (this->storage.size() < 2)
        throw EmptyContainerException();
    std::vector<int> copy = this->storage;
    std::sort(copy.begin(), copy.end());
    int s = copy[1] - copy[0];
    for (size_t i = 0; i < copy.size() - 1; i++)
    {
        if (copy[i + 1] - copy[i] < s)
            s = copy[i + 1] - copy[i];
    }
    return (static_cast<unsigned int>(s));
}

unsigned int Span::longestSpan() const {
    if (this->storage.size() < 2)
        throw EmptyContainerException();
    unsigned int min = *(std::min_element(this->storage.begin(), this->storage.end()));
    unsigned int max = *(std::max_element(this->storage.begin(), this->storage.end()));
    return (max - min);
}

void readElement(int u) {
    std::cout << u << ".";
}

void Span::display() const {
    std::cout << "CONTAINER CONTAINS :\t";
    std::for_each(this->storage.begin(), this->storage.end(), readElement);
    std::cout << "x" << std::endl;
}
