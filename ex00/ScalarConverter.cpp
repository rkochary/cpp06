#include " ScalarConverter.hpp"

double ScalarConverter::doubleNum = 0;
inf_type ScalarConverter::type = DEFAULT;

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{

}



ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::checkInf()//kisata,mtaci dzi
{
   // char *r;
  // std::cout <<str.length() << std::endl;
    if((str == "nanf" && str.length() == 4) || (str == "nan" && str.length() == 3))
        type = NOT_A_NUMBER;
    else if(str == "+inff" || str == "+inf" || str == "inff" || str == "inf")
        type = PLUS_INFINITY;
    else if(str == "-inff" || str == "-inf")
        type = MIN_INFINITY;
    
}



void ScalarConverter::convert(char* n)
{
    char *r;
    str = n;
    double num;
    if(str.length() > 1 && !strtod(n,&r))
    {
        std::cout  << "impossible chatacter" << std::endl;
        return ;
    }
    else{
     num = strtod(n,&r);
    }
    checkInf();
    if(type == NOT_A_NUMBER)
    {
        std::cout  << "char: " << "impossible" << std::endl;
        std::cout  << "int: " << "impossible" << std::endl;
        std::cout  << "float: " << "nanf" << std::endl;
        std::cout  << "double: " << "nan" << std::endl;
        return ;
    }
    if (type == PLUS_INFINITY)
    {
        std::cout  << "char: " << "impossible" << std::endl;
        std::cout  << "int: " << "impossible" << std::endl;
        std::cout  << "float: " << "inff" << std::endl;
        std::cout  << "double: " << "inf" << std::endl;
        return ;
    }
    if (type == MIN_INFINITY)
    {
        std::cout  << "char: " << "impossible" << std::endl;
        std::cout  << "int: " << "impossible" << std::endl;
        std::cout  << "float: " << "-inff" << std::endl;
        std::cout  << "double: " << "-inf" << std::endl;
        return ;
    }
    
    else if(num == 0 && (str.size() > 1 || str.find('.') != std::string::npos))
    {
        return ;
    }
    else if((num == 0 && str[0] != '0'))
    {
       // char character = static_cast<char>(str[0]);
        int integer = static_cast<int>(str[0]);
        float floatNum = static_cast<float>(str[0]);
        doubleNum = static_cast<double>(str[0]);
        std::cout << "char: " << str[0] << std::endl;
        std::cout << "float: " ;
        if (str.find('.') == std::string::npos || num == floor(num))
            std::cout << floatNum << ".0f" << std::endl;
        else
            std::cout << floatNum << "f" <<std::endl;
        std::cout << "integer: " << integer << std::endl;
        std::cout << "doubleNum: " ;
        if (str.find('.') == std::string::npos || num == floor(num))
            std::cout << doubleNum << ".0" << std::endl;
        else
            std::cout << doubleNum << std::endl;
    }
    else
    {
        doubleNum = num;
        char character = static_cast<char>(doubleNum);
        int integer = static_cast<int>(doubleNum);
        float floatNum = static_cast<float>(doubleNum);
        //std::cout << character <<std::endl;
        if(isprint(character))
            std::cout << "char: " << character << std::endl;
        else
            std::cout << "char: " << "Non displayable" << std::endl;
        std::cout << "float: " ;
        if (str.find('.') == std::string::npos || num == floor(num))
            std::cout << floatNum << ".0f" << std::endl;
        else
            std::cout << floatNum << "f" <<std::endl;
        std::cout << "integer: " << integer << std::endl;
        std::cout << "doubleNum: ";
        if (str.find('.') == std::string::npos || num == floor(num))
            std::cout << doubleNum << ".0" << std::endl;
        else
            std::cout << doubleNum << std::endl;
        }
}
