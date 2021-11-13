#ifndef scene_hpp 
#define scene_hpp

#include <iostream>
#include <vector>
#include "triangle.hpp"

template <typename Vertex>
struct Scene
{
    std::vector<Vertex> verts;
    std::vector<Triangle> tris;

    Scene() = default;
};

#endif