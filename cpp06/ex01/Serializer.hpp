#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data
{
	int value;
};

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(Serializer const &);
	Serializer &operator=(Serializer const &);

public:
	static uintptr_t	serialize(Data *ptr);
	static Data				*deserialize(uintptr_t raw);
};

#endif