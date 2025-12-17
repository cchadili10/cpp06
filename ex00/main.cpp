#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
    if(argc != 2)
        return 1;
    ScalarConverter::convert(argv[1]);
}
