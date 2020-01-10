#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include"global.h"
class Button
{
    public:
    SDL_Color color;
    Button(SDL_Rect r,GlobalInfo * g);
    Button();
    SDL_Rect pos;
    GlobalInfo *global;
     bool isClick(uint32_t time);
    bool isHover();
    void draw(SDL_Renderer * re);
 
  
    

};
class Panel:public Button 
{
    public:
    uint16_t x ,y;
    uint16_t state=0;
    bool SetState(uint16_t _s);
    Panel(SDL_Rect p,GlobalInfo *g, uint16_t _x,uint16_t _y);
    Panel();
    void _draw(SDL_Renderer * r);
};