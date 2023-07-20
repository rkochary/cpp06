#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <cstdint>

struct Data
{
    int value1;
    char value2;
};

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer &obj);
        Serializer &operator=(const Serializer &obj);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif