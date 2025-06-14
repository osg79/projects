#ifndef RAII_EXAMPLE_H
#define RAII_EXAMPLE_H

#include <cstddef>

class Collection
{
private:
    int *data; // Pointer to dynamically allocated array
public:
    Collection(size_t size);
    ~Collection();
    int &operator[](size_t index);             // Accessor for array elements
    const int &operator[](size_t index) const; // Const accessor for array elements
};

#endif // RAII_EXAMPLE_H