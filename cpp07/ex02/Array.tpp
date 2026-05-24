#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(void) : elements(NULL), elementCount(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(NULL), elementCount(n) {
	if (elementCount > 0)
		elements = new T[elementCount]();
}

template <typename T>
Array<T>::Array(const Array &other) : elements(NULL), elementCount(other.elementCount) {
	if (elementCount > 0)
	{
		elements = new T[elementCount]();
		for (unsigned int index = 0; index < elementCount; ++index)
			elements[index] = other.elements[index];
	}
}

template <typename T>
Array<T>::~Array(void) {
	delete[] elements;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other)
	{
		T *newElements = NULL;

		if (other.elementCount > 0)
		{
			newElements = new T[other.elementCount]();
			for (unsigned int index = 0; index < other.elementCount; ++index)
				newElements[index] = other.elements[index];
		}
		delete[] elements;
		elements = newElements;
		elementCount = other.elementCount;
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= elementCount)
		throw (std::exception());
	return (elements[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= elementCount)
		throw (std::exception());
	return (elements[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return (elementCount);
}

#endif