#include <iostream> // For standard input/output
#include <cstddef> // For size_t
#include "raii_example.h"

int main() {
    Collection myCollection(10); // Create a collection of size 10

    for (size_t i = 0; i < 10; ++i) {
        myCollection[i] = static_cast<int>(i * 10); // Initialize elements
    }
    for (size_t i = 0; i < 10; ++i) {
        // Print elements to verify they are initialized correctly
        std::cout << "Element at index " << i << ": " << myCollection[i] << std::endl;
    }
    // No need to manually delete myCollection; it will be automatically cleaned up
    // when it goes out of scope due to RAII (Resource Acquisition Is Initialization) principle.

    // The destructor will automatically be called when myCollection goes out of scope
    return 0;
}