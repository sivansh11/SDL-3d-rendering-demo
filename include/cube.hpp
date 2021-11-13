#ifndef cube_hpp

#include "vec3.hpp"

namespace cube
{
    Vec3 * get_verts(float size)
    {
        float side = 1 / size;
        Vec3 verts[8];

        verts[0].set(-side, -side, -side);
        verts[1].set( side, -side, -side);
        verts[2].set(-side,  side, -side);
        verts[3].set( side,  side, -side);
        verts[4].set( side, -side,  side);
        verts[5].set(-side, -side, -side);
        verts[6].set(-side,  side,  side);
        verts[7].set( side,  side,  side);

        return verts;
    }
} // namespace cube



#endif