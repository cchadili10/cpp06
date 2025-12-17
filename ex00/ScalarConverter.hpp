#pragma once

#include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator = (const ScalarConverter &other);
        ~ScalarConverter();
    public:
        void static convert(std::string value);
};
