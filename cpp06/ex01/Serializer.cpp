#include "Serializer.hpp"

// Convert a `Data*` pointer to an integer representation (`uintptr_t`).
// Uses `reinterpret_cast` to preserve the pointer's bit pattern so it
// can be stored or passed around as an integer within the same process.
uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

// Convert an integer representation (`uintptr_t`) back to a `Data*`.
// Uses `reinterpret_cast` to reinterpret the stored bits as a pointer.
Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

