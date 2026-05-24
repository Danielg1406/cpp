#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.value = 42;

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "original address: " << &data << std::endl;
	std::cout << "serialized value: " << raw << std::endl;
	std::cout << "deserialized address: " << ptr << std::endl;
	std::cout << ((ptr == &data) ? "OK" : "KO") << std::endl;

	return 0;
}

