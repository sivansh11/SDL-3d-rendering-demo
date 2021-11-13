#ifndef colorblending_hpp 
#define colorblending_hpp

#include <iostream>
#include <vector>
#include "vertex.hpp"
#include "triangle.hpp"
#include "scene.hpp"

template <typename T>
void colorBlending(Scene<T> &s)
{
    s.verts.clear();
    s.tris.clear();
    float side = 1.0f / 2;
    s.verts.push_back(Vertex(-side, -side, -side, 255, 255, 255));
    s.verts.push_back(Vertex( side, -side, -side, 0, 255, 255));
    s.verts.push_back(Vertex(-side,  side, -side, 255, 0, 255));
    s.verts.push_back(Vertex( side,  side, -side, 0, 0, 255));
    s.verts.push_back(Vertex(-side, -side,  side, 255, 255, 255));
    s.verts.push_back(Vertex( side, -side,  side, 0, 255, 0));
    s.verts.push_back(Vertex(-side,  side,  side, 255, 0, 0));
    s.verts.push_back(Vertex( side,  side,  side, 0, 0, 0));    
    s.tris.push_back(Triangle(0, 2, 1));
    s.tris.push_back(Triangle(2, 3, 1));
    s.tris.push_back(Triangle(1, 3, 5));
    s.tris.push_back(Triangle(3, 7, 5));
    s.tris.push_back(Triangle(2, 6, 3));
    s.tris.push_back(Triangle(3, 6, 7));
    s.tris.push_back(Triangle(4, 5, 7));
    s.tris.push_back(Triangle(4, 7, 6));
    s.tris.push_back(Triangle(0, 4, 2));
    s.tris.push_back(Triangle(2, 4, 6));
    s.tris.push_back(Triangle(0, 1, 4));
    s.tris.push_back(Triangle(1, 5, 4));
}

#endif