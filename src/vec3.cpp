#include "vec3.hpp"


Vec3::Vec3()
{
    x = y = z = 0.0;
}
Vec3::Vec3(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

Vec3::Vec3(const Vec3 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}
Vec3& Vec3::operator = (const Vec3 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}
void Vec3::operator += (const Vec3 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}
Vec3 Vec3::operator + (const Vec3 &v)
{
    return Vec3(x + v.x, y + v.y, z + v.z);
}

void Vec3::operator -= (const Vec3 &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
}
Vec3 Vec3::operator - (const Vec3 &v)
{
    return Vec3(x - v.x, y - v.y, z - v.z);
}

void Vec3::operator *= (const float v)
{
    x *= v;
    y *= v;
    z *= v;
}
Vec3 Vec3::operator * (const float v)
{
    return Vec3(x * v, y * v, z * v);
}

void Vec3::operator /= (const float &v)
{
    x /= v;
    y /= v;
    z /= v;
}
Vec3 Vec3::operator / (const float v)
{
    return Vec3(x / v, y / v, z / v);
}

float Vec3::operator * (const Vec3 &v)
{
    return x * v.x + y * v.y + z * v.z;
}
float Vec3::dot(const Vec3 &v)
{
    return x * v.x + y * v.y + z * v.z;
}

Vec3 Vec3::cross(const Vec3 &v)
{
    return Vec3(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);
}
void Vec3::operator %= (const Vec3 &v)
{
    *this = cross(v);
}
Vec3 Vec3::operator % (const Vec3 &v)
{
    return Vec3(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);
}

bool Vec3::operator == (const Vec3 &v)
{
    if (x == v.x && y == v.y && z == v.z) return true;
    return false;
}
bool Vec3::operator != (const Vec3 &v)
{
    if (x != v.x && y != v.y && z != v.z) return true;
    return false;
}

float Vec3::len()
{
    return sqrt(x * x + y * y + z * z);
}

void Vec3::normalize()
{
    float invMag = 1.0f / len();
    x *= invMag;
    y *= invMag;
    z *= invMag;
}

void Vec3::set(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

void Vec3::show()
{
    std::cout << x << ' ' << y << ' ' << z << std::endl;
}
Vec2 Vec3::convToVec2()
{
    return Vec2(int(x), int(y));
}