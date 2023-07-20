#include "Serializer.hpp"


int main()
{
    Data dataObj;
    dataObj.value1 = 42;
    dataObj.value2 = 'A';

    Data* originalPtr = &dataObj;

    uintptr_t serializedPtr = Serializer::serialize(originalPtr);
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    if (originalPtr == deserializedPtr) {
        std::cout << "Serialization and deserialization successful! Pointers match." << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed! Pointers do not match." << std::endl;
    }

    return 0; 
}