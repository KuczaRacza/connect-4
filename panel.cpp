#include"panel.h"
Button::Button(SDL_Rect r ,GlobalInfo * g)
{
    pos=r;
    global=g;
}
Button::Button()
{

}
bool Button::isHover()
{
     int x, y;
     SDL_GetMouseState(&x,&y);
     if(x>pos.x&&x<(pos.x+pos.h)&&y>pos.y&&y<(pos.y+pos.h))
        return true;
    return false;
}
bool Button::isClick(uint32_t time)
{
    t+=global->deltaTime;
    if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) 
        if(isHover()&&t>time&&butonup)
        {
            butonup=false;
            t=0;
            return true;
           
        }
    butonup=true;  
    return false;
}
void Button::draw(SDL_Renderer * ren)
{
    SDL_SetRenderDrawColor(ren,color.r,color.g,color.b,color.a);
    SDL_RenderFillRect(ren,&pos);
}
Panel::Panel(SDL_Rect p, GlobalInfo * g,uint16_t _x,uint16_t _y):Button(p,g)
{
    x=_x;
    y=_y;
}
Panel::Panel()
{
    
}
bool Panel::SetState(uint16_t _s)
{
    if(state==0)
    {
        state=_s;
        return true;
    }
    return false;
}
void Panel::_draw(SDL_Renderer *r)
{
    draw(r);
    if(state==1)
        SDL_SetRenderDrawColor(r,255,10,10,255);
    else if(state==2)
        SDL_SetRenderDrawColor(r,10,10,255,255);
    SDL_Rect d={pos.x+5,pos.y+5,pos.w-10,pos.h-10};
    SDL_RenderFillRect(r,&d);

}