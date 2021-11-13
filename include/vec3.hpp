#ifndef vec3_hpp
#define vec3_hpp

#include <iostream>
#include <math.h>

#include "vec2.hpp"

struct Vec3
{
    /* vector with all vector operations 
    also used to store colors*/
    union
    {
        float x;
        float r;
    };
    union
    {
        float y;
        float g;
    };
    union
    {
        float z;
        float b;
    };
    Vec3();
    Vec3(float X, float Y, float Z);

    ~Vec3() = default;

    Vec3(const Vec3 &v);
    Vec3& operator = (const Vec3 &v);

    void operator += (const Vec3 &v);

    Vec3 operator + (const Vec3 &v);

    void operator -= (const Vec3 &v);

    Vec3 operator - (const Vec3 &v);

    void operator *= (const float v);

    Vec3 operator * (const float v);

    void operator /= (const float &v);

    Vec3 operator / (const float v);

    float operator * (const Vec3 &v);

    float dot(const Vec3 &v);

    Vec3 cross(const Vec3 &v);

    void operator %= (const Vec3 &v);

    Vec3 operator % (const Vec3 &v);

    bool operator == (const Vec3 &v);

    bool operator != (const Vec3 &v);

    float len();

    void normalize();

    Vec2 convToVec2();

    void set(float X, float Y, float Z);

    void show();
};


#endif