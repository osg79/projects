#ifndef REINTERPRET_CAST_H
#define REINTERPRET_CAST_H

#include <cstdint>

struct Datablob
{
    std::uint16_t word1;
    std::uint16_t word2;
    std::uint16_t word3;
    bool status1;
    bool status2;
};

#endif // REINTERPRET_CAST_H