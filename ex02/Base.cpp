#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void)
{
    int rad = std::rand() % 3;

    if(rad == 0)
    {
        std::cout << "Generated A" << std::endl;
        return new A();
    }
    else if (rad == 1)
    {
        std::cout << "Generated B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated C" << std::endl;
        return new C();
    }
}

void identify(Base *p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "this is : A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "this is : B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "this is : C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::exception& e){}
    try
    {
        dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (const std::exception &e){}
    try
    {
        dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (const std::exception &e){}
}