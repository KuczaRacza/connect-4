#include"animation.h"
Animation::Animation(SDL_Renderer *w,GlobalInfo * g)
{   
    global=g;
    win=w;
    _r={0,0,0,0};
    FontFile=TTF_OpenFont(font,26);
    #if DEBUG
        std::cout<<"loaded font \n";
    #endif
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
void Animation::hoverAnimationGradient(SDL_Rect position)
{
     if(_r.x!=position.x)hovertime=0;
    float tMax = 250;
    if(hovertime<0)hovertime=1;
    if(hovertime>tMax)hovertime=tMax;
    float per = hovertime / tMax;
    SDL_Rect k=position;
    k.y=ceil(position.y+(position.h*(1-per))) ;  
    k.h=700-k.y  ;
    //k.h=ceil(position.h-(position.h*(1-per)));    
    float gradient = 200;
    for (size_t i = k.y; i < k.y+k.h; i++)
    {
        gradient-=gradient/600;
        SDL_SetRenderDrawColor(win,c.r,c.g,c.b,205-gradient);
        SDL_RenderDrawLine(win,k.x,i,k.x+k.w,i);
    }                   
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
void Animation::makeText(SDL_Rect _pos, SDL_Color _color,std::string message)
{
    SDL_Surface * sText= NULL;
    if(FontFile!=NULL && !message.empty())
    {
        sText=TTF_RenderText_Solid(FontFile,message.c_str(),_color);
    }
    if( sText != NULL )
    {
        SDL_Texture * tText = SDL_CreateTextureFromSurface(win,sText);
        SDL_RenderCopy(win,tText,NULL,&_pos);
        SDL_DestroyTexture(tText);
    }
    
    SDL_FreeSurface(sText);
   
}
void Animation::renderTexts()
{
    makeText({5,280,5*18,5*15},{0,0,0,255},"reset");
}