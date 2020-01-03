#include"global.h"
uint32_t GlobalInfo::setDeltaTime()
{     
        uint32_t r = SDL_GetTicks()-lastFrameTime;
        lastFrameTime =SDL_GetTicks();
        deltaTime=r;
        return r;
}
