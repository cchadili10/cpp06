#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <limits.h>
#include <iomanip> 
#include <cmath>
#include<float.h>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool is_valid_input(std::string val, int &check)
{
    if (val.empty())
        return false;
    else if (val == "-inff" || val == "+inff" || val == "nanf" || val == "nan" || val == "+inf" || val == "-inf")
    {
        if (val == "-inff" || val == "+inff" || val == "nanf")
            check = 4;
        else
            check = 5;
        return true;
    }
    bool has_dot = false;
    bool has_pos_sing = false;
    bool has_nig_sing = false;
    bool has_f = false;
    bool has_djt = false;
    for (size_t i = 0; i < val.size(); i++)
    {
        char c = val.at(i);

        if(val.size() == 1 && c >= 0 && c <= 126)
        {
            if (c >= '0' && c <= '9')
                check = 1;
            else
                check = 0;
            return true;
        }
        else if (c == 'f')
        {
            if (c != val.at(val.size() - 1))
                return false;
            has_f = true;
        }
        else if (c == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else if(c == '+' || c == '-')
        {
            if (i != 0)
                return false;
            if (has_nig_sing || has_pos_sing)
                return false;
            if(c == '+')
                has_pos_sing = true;
            else
                has_nig_sing = true;
        }
        else if(c < '0' || c > '9')
            return false;
        else
            has_djt = true;
    }
    if (has_dot && has_f && has_djt)
        check = 2;
    else if (has_dot && has_djt)
        check = 3;
    else if(has_djt)
        check = 1;
    return true;
}

void print_char(double value)
{
    std::cout << "char: " ;
    char c = static_cast<char>(value);
    if (value < 0 || value > 255)
        std::cout << "impossible";
    else if (!isprint(c))
        std::cout << "Non displayable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;
}
void print_int(double value)
{
    std::cout << "int: ";
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "impossible";
    else
    {
        int val = static_cast<int>(value);
        std::cout << val;
    }
    std::cout << std::endl;
}

void print_float(double value, int check)
{
    std::cout << "float: ";
    if (value < -FLT_MAX || value > FLT_MAX)
    {
        std::cout << "impossible";
        return ;
    }
    float f = static_cast<float>(value);
    if(check == 1 || check == 0)
        std::cout<< std::fixed  << std:: setprecision(1);
    else
        std::cout<< std::fixed  << std:: setprecision(6);
    std::cout << f ;
    std::cout << "f" << std::endl;
}
void print_double(double value, int check)
{
    std::cout << "double: ";
    if (value == HUGE_VAL || value == -HUGE_VAL)
    {
        std::cout << "impossible";
        return ;
    }
    if(check == 1 || check == 0)
        std::cout<< std::fixed  << std:: setprecision(1) ;
    else
        std::cout<< std::fixed  << std:: setprecision(6);
    std::cout << value;
    std::cout << std::endl;
}

void ScalarConverter::convert(std::string value)
{
    int check = -1;
    if (!is_valid_input(value, check))
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "impossible" << std::endl;
        std::cout << "double: " << "impossible" << std::endl;
        return;
    }
    double holder = 0;
    if(check == 0)
        holder = static_cast<char>(value.at(0));
    else if(check == 1 || check == 2 || check == 3)
    {
        holder = atof(value.c_str());
    }
    else if (check == 4)
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << value << std::endl;
        std::cout << "double: " << value.substr(0, value.size()-1) << std::endl;
        return ;
    }
    else if(check == 5)
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << value << 'f' << std::endl;
        std::cout << "double: " << value << std::endl;
        return ;
    }
    
    print_char(holder);
    print_int(holder);
    print_float(holder, check);
    print_double(holder, check);
}

