#ifndef triangle_hpp
#define triangle_hpp

struct Triangle
{
    int p1, p2, p3;
    Triangle(int vp1, int vp2, int vp3)
    {
        p1 = vp1;
        p2 = vp2;
        p3 = vp3;
    }
};

#endif