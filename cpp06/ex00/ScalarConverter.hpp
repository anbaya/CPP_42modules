#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cmath>
# include <cfloat>
# include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        static void    convert(const std::string& literal);
};

# endif // ScalarConverter_HPPinstantiable