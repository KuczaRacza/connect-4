#include"animation.h"
Animation::Animation(SDL_Renderer *w,GlobalInfo * g)
{   
    global=g;
    win=w;
    _r={0,0,0,0};
}
void Animation::verticalHower(SDL_Rect position)
{   
    if(_r.x!=position.x)hovertime=0;
    float tMax = 250;
    if(hovertime<0)hovertime=1;
    if(hovertime>tMax)hovertime=tMax;
    float per = hovertime / tMax;
    SDL_Rect k=position;
    k.y=position.y+(position.h*(1-per)) ;    
    k.h=position.h-(position.h*(1-per)) ;                                  
    SDL_SetRenderDrawColor(win,c.r,c.g,c.b,c.a*per*0.5);
    SDL_RenderFillRect(win,&k);
    _r=position;
    
}
void Animation::update()
{
    hovertime-=global->deltaTime/2;
    
}
void Animation::hoverAnimation()
{
    hovertime+=global->deltaTime;
}
void Animation::renderTilesBackground(Panel * p)
{
 
    for (size_t i = 0; i < 7; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            
            p[XY(i,j)].draw(win);
        }
        
    }
    
}
void Animation::renderTilesForeground(Panel * p)
{
 
    for (size_t i = 0; i < 7; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            
            p[XY(i,j)]._draw(win);
        }
        
    }
    
}
uint16_t Animation::XY(uint16_t x,uint16_t y)
{
    return (x+(7*y));
}