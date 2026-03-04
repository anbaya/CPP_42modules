#include "Array.hpp"

template <typename T>
Array<T>::Array(){
    this->arr = NULL;
    this->size = 0;
}

template <typename T>
Array<T>::Array(const Array &other){
    this->arr = new T[other.size];
    this->size = other.size;
    for (unsigned int i = 0; i < this->size; i++){
        this->arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other){
    if (this != &other)
    {
        delete[] this->arr;
        this->size = other.size;
        this->arr = new T[this->size];
        for (unsigned int i = 0; i < this->size; i++){
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index){
    if (index >= this->size)
        throw Array<T>::outOfRangeExeption();
    return this->arr[index];
}

template <typename T>
Array<T>::Array(unsigned int n){
    this->arr = new T[n];
    this->size = n;
}

template <typename T>
unsigned int Array<T>::Size() const {
    return this->size;
}

template <typename T>
const char * Array<T>::outOfRangeExeption::what() const throw(){
    return "out of range exeption !!";
}

template <typename T>
Array<T>::~Array(){
    delete[] this->arr;
}