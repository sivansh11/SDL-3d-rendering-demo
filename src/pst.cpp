#include "pst.hpp"

Vec3 PST(const Vec3 v, int w, int h)
{
    Vec3 res;
    float z_inv = 1.0f / v.z;
    res.x = (v.x * z_inv + 1) * w / 2;
    res.y = (-v.y * z_inv + 1) * h / 2;
    res.z = v.z;
    return res;
}