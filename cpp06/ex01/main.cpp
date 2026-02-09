#include "Serializer.hpp"

int main()
{
    Data data;
    data.i = 42;
    data.s = "Hello 42";

    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Original ptr: " << &data << std::endl;
    std::cout << "Serialized:   " << serialized << std::endl;
    std::cout << "Deserialized: " << Serializer::deserialize(serialized) << std::endl;

    if (Serializer::deserialize(serialized) == &data)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers do not match!" << std::endl;

    std::cout << "Data content: i=" << Serializer::deserialize(serialized)->i << ", s=" << Serializer::deserialize(serialized)->s << std::endl;

    return 0;
}