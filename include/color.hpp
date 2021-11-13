#ifndef color_hpp

#include <iostream>

void print_bgra(uint32_t bgra);

uint32_t get_color(uint8_t b, uint8_t g, uint8_t r, uint8_t a);
uint32_t get_color(uint8_t* bgra);


#endif