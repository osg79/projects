#include "raii_example.h"

Collection::Collection(size_t size)
{
    data = new int[size]; // Allocate memory for the array
}

Collection::~Collection()
{
    delete[] data; // Deallocate memory to prevent memory leaks
}

int &Collection::operator[](size_t index)
{
    return data[index]; // Return reference to the element at the specified index
}

const int &Collection::operator[](size_t index) const
{
    return data[index]; // Return const reference to the element at the specified index
}