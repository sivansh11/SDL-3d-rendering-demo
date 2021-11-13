#ifndef flatcolors_hpp 
#define flatcolors_hpp

#include <iostream>
#include <vector>
#include "vertex.hpp"
#include "triangle.hpp"
#include "scene.hpp"

template <typename T>
void flatcolors(Scene<T> &s)
{
    s.verts.clear();
    s.tris.clear();
    float side = 1.0f / 2;
    s.verts.push_back(Vertex(-side,-side,-side , 255, 0, 0)); // 0 near side
    s.verts.push_back(Vertex(side,-side,-side , 255, 0, 0)); // 1
    s.verts.push_back(Vertex(-side,side,-side , 255, 0, 0)); // 2
    s.verts.push_back(Vertex(side,side,-side , 255, 0, 0)); // 3
    s.verts.push_back(Vertex(-side,-side,side , 0, 255, 0)); // 4 far side
    s.verts.push_back(Vertex(side,-side,side , 0, 255, 0)); // 5
    s.verts.push_back(Vertex(-side,side,side , 0, 255, 0)); // 6
    s.verts.push_back(Vertex(side,side,side , 0, 255, 0)); // 7
    s.verts.push_back(Vertex(-side,-side,-side , 0, 0, 255)); // 8 left side
    s.verts.push_back(Vertex(-side,side,-side , 0, 0, 255)); // 9
    s.verts.push_back(Vertex(-side,-side,side , 0, 0, 255)); // 10
    s.verts.push_back(Vertex(-side,side,side , 0, 0, 255)); // 11
    s.verts.push_back(Vertex(side,-side,-side , 255, 255, 0)); // 12 right side
    s.verts.push_back(Vertex(side,side,-side , 255, 255, 0)); // 13
    s.verts.push_back(Vertex(side,-side,side , 255, 255, 0)); // 14
    s.verts.push_back(Vertex(side,side,side , 255, 255, 0)); // 15
    s.verts.push_back(Vertex(-side,-side,-side , 0, 255, 255)); // 16 bottom side
    s.verts.push_back(Vertex(side,-side,-side , 0, 255, 255)); // 17
    s.verts.push_back(Vertex(-side,-side,side , 0, 255, 255)); // 18
    s.verts.push_back(Vertex(side,-side,side , 0, 255, 255)); // 19
    s.verts.push_back(Vertex(-side,side,-side , 255, 255, 255)); // 20 top side
    s.verts.push_back(Vertex(side,side,-side , 255, 255, 255)); // 21
    s.verts.push_back(Vertex(-side,side,side , 255, 255, 255)); // 22
    s.verts.push_back(Vertex(side,side,side , 255, 255, 255)); // 2
    s.tris.push_back(Triangle(0,2, 1));
    s.tris.push_back(Triangle(2,3,1));
    s.tris.push_back(Triangle(4,5, 7));
    s.tris.push_back(Triangle(4,7,6));
    s.tris.push_back(Triangle(8,10, 9));
    s.tris.push_back(Triangle(10,11,9));
    s.tris.push_back(Triangle(12,13,15));
    s.tris.push_back(Triangle(12,15,14));
    s.tris.push_back(Triangle(16,17,18));
    s.tris.push_back(Triangle(18,17,19));
    s.tris.push_back(Triangle(20,23,21));
    s.tris.push_back(Triangle(20,22,23));
}

#endif