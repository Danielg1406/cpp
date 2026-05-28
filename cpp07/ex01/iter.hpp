#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *array, const std::size_t length, void (*function)(T &)) {
	for (std::size_t index = 0; index < length; ++index)
		function(array[index]);
}

template <typename T>
void iter(T *array, const std::size_t length, void (*function)(const T &)) {
	for (std::size_t index = 0; index < length; ++index)
		function(array[index]);
}

template <typename T>
void iter(const T *array, const std::size_t length, void (*function)(const T &)) {
	for (std::size_t index = 0; index < length; ++index)
		function(array[index]);
}

#endif