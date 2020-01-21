#define DEBUG true
#include<SDL2/SDL.h>
#include<iostream>
class GlobalInfo
{
    public:
    uint32_t deltaTime;
    uint32_t lastFrameTime;
    uint32_t setDeltaTime();
    uint32_t lastClick;
    uint32_t syncTime;
    uint32_t getSyncTime();
    uint32_t lastSyncTime;
    SDL_Event e;
    bool up;
    bool mouseButtonUp();
    bool getMouseLeft;

};