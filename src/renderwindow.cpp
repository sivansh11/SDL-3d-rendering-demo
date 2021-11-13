#include "renderwindow.hpp"
#include "color.hpp"
#include <iostream>


RenderWindow::RenderWindow(const char* title, int width, int height)
{
    // handels window, renderer texture creation and also creates an array of bools for keyboard inputs
    w = width;
    h = height;
    running = true;
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (window) std::cout << "Window Created..." << std::endl;
    else 
    {   
        std::cout << "Window creation error:" << SDL_GetError();
        running = false;
    }
    if (running)
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) std::cout << "Renderer Created..." << std::endl;
        else
        {
            std::cout << "Renderer creation error:" << SDL_GetError();
            running = false;
        }
    }
    if (running)
    {
        framebuffer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);
        if (framebuffer) std::cout << "framebuffer Created..." << std::endl;
        else
        {
            std::cout << "framebuffer creation error:" << SDL_GetError();
            running = false;
        }
        for(int i = 0; i < 322; i++) 
        KEYS[i] = false;
    }
}

RenderWindow::~RenderWindow()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(framebuffer);
    SDL_Quit();
    std::cout << "Destroyed window, renderer, framebuffer" << std::endl;
}

void RenderWindow::RenderFrameBuffer(uint32_t *pixels)
{
    SDL_UpdateTexture(framebuffer, NULL, pixels, w * sizeof(Uint32));
    SDL_RenderCopy(renderer, framebuffer, NULL, NULL);
    SDL_RenderPresent(renderer);
}
void RenderWindow::calculateFps()
{
    // fps calculation
    // NUM SAMPLES can be changed to smooth out sudden displayed fps changes 
    static const int NUM_SAMPLES = 10;
    static float frameTimes[NUM_SAMPLES];
    static int currentFrame = 0;

    static float prevTicks = SDL_GetTicks();
    float currentTicks = SDL_GetTicks();

    frameTime = currentTicks -prevTicks;
    frameTimes[currentFrame % NUM_SAMPLES] = frameTime;

    prevTicks = currentTicks;

    int count;

    currentFrame++;
    if (currentFrame < NUM_SAMPLES)
    {
        count = currentFrame;
    }
    else
    {
        count = NUM_SAMPLES;
    }
    
    float frameTimeAverage = 0;
    for (int i = 0; i < count; i++)
        frameTimeAverage += frameTimes[i];
    frameTimeAverage /= count;

    if (frameTimeAverage > 0)
    {
        fps = 1000.f / frameTimeAverage;
    }
    else
    {
        fps = -1;
    }
}