#ifndef vertex_hpp
#define vertex_hpp

#include "vec3.hpp"
#include "color.hpp"

struct Vertex
{
    Vec3 pos;
    Vec3 color;


    Vertex() = default;
    Vertex(float X, float Y, float Z, float r, float g, float b)
    {
        pos.set(X, Y, Z);
        color.set(r, g, b);
    }
    ~Vertex() = default;

    Vertex(const Vertex &v)
    {
        pos = v.pos;
        color = v.color;
    }
    Vertex& operator = (const Vertex &v)
    {
        pos = v.pos;
        color = v.color;
        return *this;
    }
    Vertex operator + (const Vertex &v)
    {
        return Vertex(pos.x + v.pos.x, pos.y + v.pos.y, pos.z + v.pos.z, color.r + v.color.r, color.g + v.color.g, color.b + v.color.b);
    }
    Vertex operator - (const Vertex &v)
    {
        return Vertex(pos.x - v.pos.x, pos.y - v.pos.y, pos.z - v.pos.z, color.r - v.color.r, color.g - v.color.g, color.b - v.color.b);
    }
    Vertex operator * (const float v)
    {
        return Vertex(pos.x * v, pos.y * v, pos.z * v, color.r * v, color.g * v, color.b * v);
    }
    Vertex operator / (const float v)
    {
        return Vertex(pos.x / v, pos.y / v, pos.z / v, color.r / v, color.g / v, color.b / v);
    }
    Vertex operator + (const float v)
    {
        return Vertex(pos.x + v, pos.y + v, pos.z + v, color.r, color.g, color.b);
    }
    Vertex operator - (const float v)
    {
        return Vertex(pos.x - v, pos.y - v, pos.z - v, color.r, color.g, color.b);
    }
    void set(float x, float y, float z, int r, int g, int b)
    {
        pos.set(x, y, z);
        color.set(r, g, b);
    }
    uint32_t col()
    {
        return get_color(color.z, color.y, color.x, 255);
    }
    void show()
    {
        std::cout << pos.x << ' ' << pos.y << ' ' << pos.z << ' ' << color.x << ' ' << color.y << ' ' << color.z << std::endl;
    }
};



#endif