#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data = {42, 3.14f, "Hello, world!"};

    uintptr_t raw = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Original Data: " << data.a << ", " << data.b << ", " << data.c << std::endl;
    std::cout << "Deserialized Data: " << deserializedData->a << ", " << deserializedData->b << ", " << deserializedData->c << std::endl;

    return 0;
}
