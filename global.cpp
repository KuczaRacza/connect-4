#include"global.h"
uint32_t GlobalInfo::setDeltaTime()
{     
        uint32_t r = SDL_GetTicks()-lastFrameTime;
        lastFrameTime =SDL_GetTicks();
        deltaTime=r;
        return r;
}
uint32_t GlobalInfo::getSyncTime()
{     
        uint32_t r = SDL_GetTicks()-lastSyncTime;
        lastSyncTime =SDL_GetTicks();
        syncTime=r;
        return 16-r;
}
bool GlobalInfo::mouseButtonUp()
{       
        
        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
                #if DEBUG
                                std::cout<<"pressed"<<'\n';
                #endif
                if(up)
                {
                        up=false;
                        return true;
                        #if DEBUG
                                std::cout<<"click"<<'\n';
                        #endif
                        

                }
                return false;
                
        }
        else
        {
                up = true;
                return false;
        }
        
}