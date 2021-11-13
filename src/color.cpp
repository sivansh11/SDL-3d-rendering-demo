#include "color.hpp"


uint32_t get_color(uint8_t b, uint8_t g, uint8_t r, uint8_t a)
{
    uint32_t res;
    res = b | g << 8 | r << 16 | a << 24;
    return res;
}

uint32_t get_color(uint8_t* bgra)
{
    uint32_t res;
    res = bgra[0] | bgra[1] << 8 | bgra[2] << 16 | bgra[3] << 24;
    return res;
}

void print_bgra(uint32_t bgra)
{
    uint8_t res[4];
    *(uint32_t *)res = bgra;

    std::cout << int(res[0]) << ' ' << int(res[1]) << ' ' << int(res[2]) << ' ' << int(res[3]) << std::endl;
}
