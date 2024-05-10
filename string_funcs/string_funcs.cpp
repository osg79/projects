#include "string_funcs/string_funcs.h"

int main()
{
    std::string address("1234 Patrick Henry St, Apt 101");
    size_t idx{};
    int street_number = std::stoi(address, &idx);
    std::cout << "Address: " << address << std::endl;
    std::cout << "Street Number: " << street_number << std::endl;
    std::cout << "Index: " << idx << std::endl;
    return 0;
}