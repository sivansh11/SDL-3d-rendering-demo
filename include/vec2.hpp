#ifndef vec2_hpp
#define vec2_hpp

struct Vec2
{
    float x;
    float y;

    Vec2()
    {
        x = y = 0.0f;
    }

    Vec2(float X, float Y)
    {
        x = X;
        y = Y;
    }

    ~Vec2() = default;

    Vec2(const Vec2 &v)
    {
        x = v.x;
        y = v.y;
    }

    Vec2& operator = (const Vec2 &v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    void operator += (const Vec2 &v)
    {
        x += v.x;
        y += v.y;
    }

    Vec2 operator + (const Vec2 &v)
    {
        return Vec2(x + v.x, y + v.y);
    }

    void operator -= (const Vec2 &v)
    {
        x -= v.x;
        y -= v.y;
    }

    Vec2 operator - (const Vec2 &v)
    {
        return Vec2(x - v.x, y - v.y);
    }

    void operator *= (const float v)
    {
        x *= v;
        y *= v;
    }

    Vec2 operator * (const float v)
    {
        return Vec2(x * v, y * v);
    }

    void operator /= (const float &v)
    {
        x /= v;
        y /= v;
    }

    Vec2 operator / (const float v)
    {
        return Vec2(x / v, y / v);
    }

    bool operator == (const Vec2 &v)
    {
        if (x == v.x && y == v.y) return true;
        return false;
    }

    bool operator != (const Vec2 &v)
    {
        return !operator==(v);
    }

    float len()
    {
        return sqrt(x * x + y * y);
    }

    void normalize()
    {
        float invMag = 1.0f /len();
        x *= invMag;
        y *= invMag;
    }

    void set(float X, float Y)
    {
        x = X;
        y = Y;
    }

    void show()
    {
        std::cout << x << ' ' << y << std::endl;
    }
};


#endif