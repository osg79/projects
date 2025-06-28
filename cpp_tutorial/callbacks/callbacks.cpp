#include <iostream>   // For std::cout
#include <functional> // For std::function
#include <vector>     // For std::vector
#include <algorithm>  // For std::for_each
#include <cstdint>    // for std::uint64_t

// Function
void square(std::uint64_t &value)
{
    value *= value;
}

// Function pointer
void (*square_pointer)(std::uint64_t &) = square;

// Functor
class Square
{
public:
    void operator()(std::uint64_t &value)
    {
        value *= value;
    }
};

// Lambda
auto square_lambda = [](std::uint64_t &value)
{ value *= value; };

int main()
{
    std::vector<std::uint64_t> numbers = {1, 2, 3, 4};
    // Define a lambda for printing vector element
    auto print = [](const std::uint64_t &number)
    { std::cout << number << std::endl; };

    std::cout << "Before:" << std::endl;
    std::for_each(numbers.cbegin(), numbers.cend(), print);

    std::cout << "After: Function" << std::endl;
    std::for_each(numbers.begin(), numbers.end(), square);
    std::for_each(numbers.cbegin(), numbers.cend(), print);

    std::cout << "After: Function pointer" << std::endl;
    std::for_each(numbers.begin(), numbers.end(), square_pointer);
    std::for_each(numbers.cbegin(), numbers.cend(), print);

    std::cout << "After: Functor" << std::endl;
    Square square_functor{};
    std::for_each(numbers.begin(), numbers.end(), square_functor);
    std::for_each(numbers.cbegin(), numbers.cend(), print);

    std::cout << "After: Lambda" << std::endl;
    std::for_each(numbers.begin(), numbers.end(), square_lambda);
    std::for_each(numbers.cbegin(), numbers.cend(), print);

    // Define a std::function
    std::function<void(std::uint64_t &)> std_fn{};
    // Wrap a function
    std_fn = square;
    // Wrap a function pointer
    std_fn = square_pointer;
    // Wrap a functor
    std_fn = square_functor;
    // Wrap a lambda
    std_fn = square_lambda;
    // Print results
    std::cout << "After: std::function" << std::endl;
    std::for_each(numbers.begin(), numbers.end(), std_fn);
    std::for_each(numbers.cbegin(), numbers.cend(), print);

    return 0;
}