#ifndef graphics_hpp
#define graphics_hpp

#include "color.hpp"

#include <math.h>
#include <iostream>

#include "vec3.hpp"

template <typename Vertex>
struct Graphics
{
    /*
    draws custom graphics to a buffer (pixel buffer)
    */

    int width;
    int height;
    int total;
    uint32_t reset_color;
    uint32_t *pixels;
    
    Graphics();
    Graphics(int w, int h, uint32_t *px, uint32_t color)
    {
        width = w;
        height = h;
        total = w * h;
        reset_color = color;
        pixels = px;
    }

    void reset()
    {
        for (int i = 0; i < total; i++)
            pixels[i] = reset_color;
    }

    void draw_line(Vec2 v0, Vec2 v1, uint32_t color)
    {
        /* straight line between 2 points */

        int x0 = v0.x, x1 = v1.x, y0 = v0.y, y1=v1.y;
        float dx = abs(x1 - x0);
        int sx = x0 < x1 ? 1 : -1;
        float dy = -abs(y1 - y0);
        int sy = y0 < y1 ? 1 : -1;
        float error = dx + dy;
        float error2;
        while (true)
        {
            pixels[y0 * width + x0] = color;

            if (x0 == x1 && y0 == y1) break;
            error2 = 2 * error;

            if (error2 >= dy)
            {
                error += dy;
                x0 += sx;
            }
            if (error2 <= dx)
            {
                error += dx;
                y0 += sy;
            }
        }
    }
    void draw_triangle(Vec2 v1, Vec2 v2, Vec2 v3, uint32_t colour)  // draws triangle
    {
        draw_line(v1, v2, colour);
        draw_line(v2, v3, colour);
        draw_line(v3, v1, colour);
    }

    
    void draw_filled_triangle(Vertex ver0, Vertex ver1, Vertex ver2, uint32_t color)
    {
        // each vertex has color data. The color is then interpolated between the verticies
        Vertex* v0 = &ver0;
        Vertex* v1 = &ver1;
        Vertex* v2 = &ver2;

        if (v1->pos.y < v0->pos.y) std::swap(v0, v1);
        if (v2->pos.y < v1->pos.y) std::swap(v1, v2);
        if (v1->pos.y < v0->pos.y) std::swap(v0, v1);

        if (v0->pos.y == v1->pos.y)
        {
            if (v1->pos.x < v0->pos.x) std::swap(v0, v1);
            draw_flat_top_triangle(*v0, *v1, *v2, color);
        }
        else if (v1->pos.y == v2->pos.y)
        {
            if (v2->pos.x < v1->pos.x) std::swap(v1, v2);
            draw_flat_bottom_triangle(*v0, *v1, *v2, color);
        }
        else
        {
            float alphaSplit = (v1->pos.y - v0->pos.y) / (v2->pos.y - v0->pos.y);
            auto vi = *v0 + ((*v2 - *v0) * alphaSplit);

            if (v1->pos.x < vi.pos.x)
            {
                draw_flat_bottom_triangle(*v0, *v1, vi, color);
                draw_flat_top_triangle(*v1, vi, *v2, color);
            }
            else
            {
                draw_flat_bottom_triangle(*v0, vi, *v1, color);
                draw_flat_top_triangle(vi, *v1, *v2, color);
            }
        }
    }
    void draw_flat_top_triangle(Vertex v0, Vertex v1, Vertex v2, uint32_t color)  // helper function to draw filled triangle
    {
        float del_y = v2.pos.y - v0.pos.y;
        Vertex dv0 = (v2 - v0) / del_y;
        Vertex dv1 = (v2 - v1) / del_y;
        Vertex vE1 = v1;

        draw_flat_triangle(v0, v1, v2, dv0, dv1, vE1, color);
    }
    void draw_flat_bottom_triangle(Vertex v0, Vertex v1, Vertex v2, uint32_t color)  // helper function to draw filled triangle
    {
        float del_y = v2.pos.y - v0.pos.y;
        Vertex dv0 = (v1 - v0) / del_y;
        Vertex dv1 = (v2 - v0) / del_y;
        Vertex vE1 = v0;

        draw_flat_triangle(v0, v1, v2, dv0, dv1, vE1, color);
    }
    void draw_flat_triangle(Vertex v0, Vertex v1, Vertex v2, Vertex dv0, Vertex dv1, Vertex vE1, uint32_t color)  // helper function to draw filled triangle
    {   
        Vertex vE0 = v0;

        int yStart = std::max((int)ceil(v0.pos.y - 0.5f), 0);
        int yEnd = std::min((int)ceil(v2.pos.y - 0.5f), height - 1);

        vE0 = vE0 + (dv0 * (float(yStart) + 0.5f - v0.pos.y));
        vE1 = vE1 + (dv1 * (float(yStart) + 0.5f - v0.pos.y));

        for (int y = yStart; y < yEnd; y++, vE0 = vE0 + dv0, vE1 = vE1 + dv1)
        {
            int xStart = std::max((int)ceil(vE0.pos.x - 0.5f), 0);
            int xEnd = std::min((int)ceil(vE1.pos.x - 0.5f), width - 1);

            auto line = vE0;

            float dx = vE1.pos.x - vE0.pos.x;
            auto dline = (vE1 - line) / dx;

            line = line + (dline * (float(xStart) + 0.5f - vE0.pos.x));

            for (int x = xStart; x < xEnd; x++, line = line + dline)
            {   
                pixels[y * width + x] = line.col();
            }
        }
    }  
};

#endif