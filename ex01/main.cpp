#include "Serializer.hpp"

int main()
{
    Data data;
    data.num = 42;
    data.str = "Hello 42";

    
    Data* original = &data;

    uintptr_t raw = Serializer::serialize(original);

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer : " << original << std::endl;
    std::cout << "Raw value        : " << raw << std::endl;
    std::cout << "Restored pointer : " << restored << std::endl;

    std::cout << "\nData check:" << std::endl;
    std::cout << "n = " << restored->num << std::endl;
    std::cout << "s = " << restored->str << std::endl;

    return 0;
}