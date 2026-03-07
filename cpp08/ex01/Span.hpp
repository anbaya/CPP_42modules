#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span{
    private:
        unsigned int _N;
        std::vector<int> _numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(int num);
        template <typename it>
        void addNumber(it start, it end){
            for (; start != end; ++start){
                addNumber(*start);
            }
        }
        unsigned int shortestSpan();
        unsigned int longestSpan();
        class itsFullEx : public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "container is full exeption !!";
                }
        };
};

#endif //SPAN_HPP