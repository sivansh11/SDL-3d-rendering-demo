#include <iostream>
#include <SDL.h>
#include "color.hpp"
#include "renderwindow.hpp"
#include "graphics.hpp"
#include "vec3.hpp"
#include "mat.hpp"
#include "pst.hpp"
#include "vertex.hpp"
#include "triangle.hpp"
#include <vector>
#include "scene.hpp"
#include "flatscolors.hpp"
#include "colorblending.hpp"

int main(int argc, char ** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;
    int width, height;

    width = 600;
    height = 600;
    RenderWindow renderwindow("renderererere", width, height);

    uint32_t * pixels = new Uint32[width * height]; // pixel buffer used to draw custom graphics in graphics.hpp

    Graphics<Vertex> gfx(width, height, pixels, get_color(0, 0, 0, 255)); // initializes graphics 

    // todo: how tf to do scenes ???? no idea
    // this scene is not correct
    Scene<Vertex> currScene;

    //colorBlending and flatcolors are 2 demo scenes 
    //actual Scenes not implimented :(

    // flatcolors(currScene);
    colorBlending(currScene);


    Mat X(3, 3), Y(3, 3), Z(3, 3);  // X, Y, Z are rotation in x, y, z axis
    Vec3 offset(0, 0, 2);  // move cube in z direction

    float a=0, b=0, g=0;
    float maxFps = 120;
    float startTicks, dt, msPerFrame = 1000.0f / maxFps;

    bool cull_flags[currScene.tris.size()];

    std::vector<Vertex> new_verts;  

    while (renderwindow.isRunning())
    {   
        startTicks = SDL_GetTicks();
        // handel events and keyboard inputs
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    renderwindow.stopRun();
                    break;
                case SDL_KEYDOWN:
                    renderwindow.KEYS[event.key.keysym.sym] = true;
                    break;
                case SDL_KEYUP:
                    renderwindow.KEYS[event.key.keysym.sym] = false;           
                    break;
            }
        }
        if (renderwindow.KEYS['q'])
            a += 0.01;
        if (renderwindow.KEYS['w'])
            a -= 0.01;
        if (renderwindow.KEYS['a'])
            b += 0.01;
        if (renderwindow.KEYS['s'])
            b -= 0.01;
        if (renderwindow.KEYS['z'])
            g += 0.01;
        if (renderwindow.KEYS['x'])
            g -= 0.01;
        if (renderwindow.KEYS['r'])
        {
            a = b = g = 0;
        }
        gfx.reset();  // resets pixel buffer to some reset color

        // sets rotation matracies 
        // a, b, g are rotation angle in x, y, z respectively 
        rotateX(X, a);
        rotateY(Y, b);
        rotateZ(Z, g);

        Mat rotate = X * Y * Z; // final rotation matrix  (prolly could have have optimized it further by directly calculating rotion rather than seprately then multiplying)

        new_verts.clear(); // transformed verticies are stored here

        // vertex transformation
        for (int i = 0; i < currScene.verts.size(); i++)  
        {   
            new_verts.push_back(Vertex());
            new_verts[i].pos = (rotate * currScene.verts[i].pos) + offset;
            new_verts[i].color = currScene.verts[i].color;
        }

        // backface culling
        for (int i = 0; i < currScene.tris.size(); i++)
        {
            Vec3 v0 = new_verts[currScene.tris[i].p1].pos;
            Vec3 v1 = new_verts[currScene.tris[i].p2].pos;
            Vec3 v2 = new_verts[currScene.tris[i].p3].pos;

            if ((((v1 - v0) % (v2 - v0)) * v0) >= 0)
                cull_flags[i] = true;
            else
                cull_flags[i] = false;
        }

        // another vertex transformtion (convertion from world space to screen space)
        for (int i = 0; i < currScene.verts.size(); i++)
        {
            new_verts[i].pos = PST(new_verts[i].pos, width, height);
        }

        // triangles are drawn
        for (int i = 0; i < currScene.tris.size(); i++)
        {
            if (!cull_flags[i])
                {   
                    auto tri = currScene.tris[i];
                    gfx.draw_filled_triangle(new_verts[tri.p1], new_verts[tri.p2], new_verts[tri.p3], get_color(255, 255, 255, 255));
                    gfx.draw_triangle(new_verts[tri.p1].pos.convToVec2(), new_verts[tri.p2].pos.convToVec2(), new_verts[tri.p3].pos.convToVec2(), get_color(255,255,255,255));
                }
        }

        renderwindow.RenderFrameBuffer(pixels);
        renderwindow.calculateFps();
        std::cout << "FPS:" << renderwindow.fps << std::endl;float fps;
        dt = SDL_GetTicks() - startTicks;
        if (msPerFrame > dt)
        {
            SDL_Delay(msPerFrame - dt);
        }
    }

    delete[] pixels;

    return 0;
}