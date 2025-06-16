#include "reinterpret_cast.h"
#include <cstring>
#include <iostream>

int main()
{
    std::uint8_t *bytes = new std::uint8_t[sizeof(Datablob)];
    memset(bytes, 0U, sizeof(Datablob));

    Datablob data{10U, 11U, 12U, true, false};
    memcpy(bytes, &data, sizeof(Datablob));

    Datablob *read_data = reinterpret_cast<Datablob *>(bytes);
    std::cout << read_data->word1 << std::endl;
    std::cout << read_data->word2 << std::endl;
    std::cout << read_data->word3 << std::endl;
    std::cout << std::boolalpha;
    std::cout << read_data->status1 << std::endl;
    std::cout << read_data->status2 << std::endl;

    delete[] bytes;
    return 0;
}