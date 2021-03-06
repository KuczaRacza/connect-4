#include"game.h"
Game::Game(SDL_Renderer *r,GlobalInfo * g):Animation(r,g)
{   
    
    global=g;
    ren=r; 
    P = new Panel[42];
    for (size_t i = 0; i < 7; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            SDL_Rect r = {150+(i*100),100+(j*100),100,100};
            P[XY(i,j)]=Panel(r,global,i,j);
            P[XY(i,j)].color={200,200,200,255};
        }
        
    }
    reset= Button({25,350,50,50},global);
    reset.color={255,255,20,255};
}


void Game::game()
{   
    uint8_t ho= 13;
    if(reset.isClick(20))
    {
        restart();
    }
    
    for (size_t i = 0; i < 7; i++)
    {   
        
        for (size_t j = 0; j < 6; j++)
        {
            if(P[XY(i,j)].isClick(80)&&!win)
            {
                uint16_t h = setLowest(i);
                if(h!=13)
                {
                    if(a)
                    {
                        #if DEBUG
                            std::cout<<"placed on "<<h<<'\n';
                        #endif
                         if(P[XY(i,h)].SetState(1))
                            a=!a;
                    }
                    else
                    {
                         #if DEBUG
                            std::cout<<"placed on "<<h<<'\n';
                        #endif
                        if(P[XY(i,h)].SetState(2))
                        a=!a;
                    }
                       
                    
                }
            }
            if(checkHorizontal(i,j))
            {
                win=true;
                win_pos={i,j,i+3,j};
                for (size_t k = 0; k < 4; k++)
                {
                    P[XY(i+k,j)].color={10,250,25,255};
                }
                
            }
            else if(checkVertical(i,j))
            {
                win=true;
                win_pos={i,j,i,j+3};
                for (size_t k = 0; k < 4; k++)
                {
                    P[XY(i,j+k)].color={10,250,25,255};
                }
            }
            else if(checkRightDown(i,j))
            {
                win=true;
                win_pos={i,j,i+3,j-3};
                for (size_t k = 0; k < 4; k++)
                {
                    P[XY(i+k,j-k)].color={10,250,25,255};
                }
            }
            else if(checkRightUp(i,j))
            {
                win=true;
                win_pos={i,j,i+3,j+3};
                for (size_t k = 0; k < 4; k++)
                {
                    P[XY(i+k,j+k)].color={10,250,25,255};
                }
            }
            if(P[XY(i,j)].isHover()) ho = i;
           
        }
     
        
    }
    
    reset.draw(ren);
   

    if(ho!=13)hoverAnimation();
    if(a)c={230,0,0,255};
    else c={0,0,230,255};
    renderTilesBackground(P);
    hoverAnimationGradient({150+(100*ho),100,100,600});
    renderTilesForeground(P);
    renderTexts();
     if(win)
    {
        int x1= win_pos.x*100 +200;
        int x2= win_pos.w*100 +200;
        int y1= win_pos.y*100 +150;
        int y2= win_pos.h*100 +150;
        SDL_SetRenderDrawColor(ren,10,10,10,255);
        SDL_RenderDrawLine(ren,x1,y1,x2,y2);
    }

    update();

    
}
bool Game::checkHorizontal(uint16_t i, uint16_t j)
{
     if(i<4)
        if(P[XY(i,j)].state==P[XY(i+1,j)].state&&P[XY(i+1,j)].state==P[XY(i+2,j)].state&&P[XY(i+2,j)].state==P[XY(i+3,j)].state&&P[XY(i,j)].state!=0)
            return true;
    return false;
}
bool Game::checkVertical(uint16_t i ,uint16_t j)
{
    if(j<3)
        if(P[XY(i,j)].state==P[XY(i,j+1)].state&&P[XY(i,j+1)].state==P[XY(i,j+2)].state&&P[XY(i,j+2)].state==P[XY(i,j+3)].state&&P[XY(i,j)].state!=0)
            return true;
    return false;
}
bool Game::checkRightUp(uint16_t i ,uint16_t j)
{
    if(i<4&&j<3)
    if(P[XY(i,j)].state==P[XY(i+1,j+1)].state&&P[XY(i+1,j+1)].state==P[XY(i+2,j+2)].state&&P[XY(i+2,j+2)].state==P[XY(i+3,j+3)].state&&P[XY(i,j)].state!=0)
        return true;
    return false;
}
bool Game::checkRightDown(uint16_t i ,uint16_t j)
{
    if(j>3&&i<4)
    if(P[XY(i,j)].state==P[XY(i+1,j-1)].state&&P[XY(i,j)].state==P[XY(i+2,j-2)].state&&P[XY(i,j)].state==P[XY(i+3,j-3)].state&&P[XY(i,j)].state!=0)
        return true;
    return false;
}
uint16_t Game::setLowest(uint16_t x)
{
   for (int i = 5; i >= 0; i--)
   {
       if(i>=0&&i<6)
       if(P[XY(x,i)].state==0)
           return i;
   }
   return 13;
   
}
void Game::restart()
{
    for (size_t i = 0; i < 42; i++)
    {
        P[i].state=0;
        P[i].color={200,200,200,255};
    }
    win=false;
    
}
