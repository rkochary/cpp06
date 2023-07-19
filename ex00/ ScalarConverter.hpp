#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>

enum inf_type
{
    PLUS_INFINITY = 0,
    MIN_INFINITY = 1,
    NOT_A_NUMBER = 2,
    DEFAULT = 3
};

class  ScalarConverter
{
        static std::string str;
        static double doubleNum;
        static inf_type type;
        static bool isInt();
        static bool isDouble();
        static bool isChar();
        static void checkInf();
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter operator=(const ScalarConverter &obj);
        ~ScalarConverter();
        static void convert(char* n);
};

#endif

//strtod 
//setprecision <iomanip>
// literals -> INFINITY -INFINITY +INFINITY NAN

 
