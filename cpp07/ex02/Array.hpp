# ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T> class Array{
    private:
        T *arr;
        unsigned int size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        T &operator[](unsigned int index);
        ~Array();
        class outOfRangeExeption : public std::exception{
            public:
                virtual const char *what() const throw();
        };
        unsigned int Size() const;
        
};

#include "Array.tpp"

#endif //ARRAY_HPP