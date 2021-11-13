#ifndef renderwindow_hpp

#include <SDL.h>

class RenderWindow
{
    /* 
    wrapper around SDL WINDOW, SDL RENDERER and SDL TEXTURE
    also handels the pixel buffer that is used to draw custom graphics in graphics.hpp
    */

public:
    RenderWindow(const char* title, int width, int height);
    ~RenderWindow();

    bool isRunning() {return running;}
    void RenderFrameBuffer(uint32_t *pixels);

    void stopRun() {running = false;} 

    void calculateFps();

    float fps;

public:
    bool KEYS[322];

private:
    float frameTime;
    int w;
    int h;
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *framebuffer;
    bool running;
};

#endif