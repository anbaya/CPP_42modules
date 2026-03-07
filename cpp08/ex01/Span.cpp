#include "Span.hpp"

Span::Span() :_N(5){}

Span::Span(unsigned int n) :_N(n){}

Span::Span(const Span &other){
    this->_N = other._N;
    this->_numbers = other._numbers;
}

Span &Span::operator=(const Span &other){
    if (this != &other){
        this->_N = other._N;
        this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int num){
    if (this->_numbers.size() < this->_N){
        this->_numbers.push_back(num);
    }
    else
        throw itsFullEx();
}

unsigned int Span::longestSpan(){
    if (this->_numbers.size() < 2) throw std::logic_error("Not enough elements");
    long long min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
    long long max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
    return max - min;
}

unsigned int Span::shortestSpan(){
    if (this->_numbers.size() < 2) throw std::logic_error("Not enough elements");
    std::vector<int> tmp = this->_numbers;
    std::sort(tmp.begin(), tmp.end());
    long long minDiff = tmp[1] - tmp[0];
    for(size_t i = 1; i < tmp.size() - 1; i++){
        long long diff = tmp[i + 1] - tmp[i];
        if (diff < minDiff)
            minDiff = diff;
    }
    return static_cast<unsigned int>(minDiff);
}