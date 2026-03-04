#include "Array.hpp"

template <typename T>
Array<T>::Array(){
    this->arr = NULL;
    this->_size = 0;
}

template <typename T>
Array<T>::Array(const Array &other){
    this->arr = new T[other._size];
    this->_size = other._size;
    for (unsigned int i = 0; i < this->_size; i++){
        this->arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other){
    if (this != &other)
    {
        delete[] this->arr;
        this->_size = other._size;
        this->arr = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++){
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index){
    if (index >= this->_size)
        throw Array<T>::outOfRangeExeption();
    return this->arr[index];
}

template <typename T>
Array<T>::Array(unsigned int n){
    this->arr = new T[n];
    this->_size = n;
}

template <typename T>
unsigned int Array<T>::size() const {
    return this->_size;
}

template <typename T>
const char * Array<T>::outOfRangeExeption::what() const throw(){
    return "out of range exeption !!";
}

template <typename T>
Array<T>::~Array(){
    delete[] this->arr;
}