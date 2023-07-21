#include "Base.hpp"


Base *generate(void)
{
    int random = rand();
    if(random % 3 == 3 )
        return new A();
    else if(random % 3 == 2)
        return new B();
    return new C();
}

void identify(Base *p)
{
    A *a;
    B *b;
    C *c;
    a = dynamic_cast<A*>(p);
    b = dynamic_cast<B*>(p);
    c = dynamic_cast<C*>(p);
    if(a)
        std::cout << "The type of object is A" << std::endl;
    if(b)
        std::cout << "The type of object is B" << std::endl;
    if(c)
        std::cout << "The type of object is C" << std::endl;
}

void identify(Base& p)
{
    
    try
    {
        (void)dynamic_cast<A&>(p);
         std::cout << "The type of object is A" << std::endl;
    }
    catch(...)
    {   
    }
    try
    {
        (void)dynamic_cast<B&>(p);
         std::cout << "The type of object is B" << std::endl;
    }
    catch(...)
    {
    }
    try
    {
        (void)dynamic_cast<C&>(p);
         std::cout << "The type of object is C" << std::endl;
    }
    catch(...)
    {
    }
    
}

int main()
{
    // Generate a random object and identify its type using the pointer version of identify
    Base* randomObject = generate();
    std::cout << "Identifying using pointer: ";
    identify(randomObject);

    // Generate another random object and identify its type using the reference version of identify
    Base* anotherRandomObject = generate();
    std::cout << "Identifying using reference: ";
    identify(*anotherRandomObject);

    // Clean up memory
    delete randomObject;
    delete anotherRandomObject;

    return 0;
}