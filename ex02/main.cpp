#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));
    Base *rand;
    A a;
    B b;
    C c;
    rand = generate();

    identify(rand);
    identify(*rand);
    identify(a);
    identify(b);
    identify(c);

    delete rand;

    return 0;
}
