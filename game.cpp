#include"game.h"
Game::Game(SDL_Renderer *r,GlobalInfo * g)
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
    
   
}
void Game::test()
{

}
uint16_t Game::XY(uint16_t x,uint16_t y)
{
    return (x+(7*y));
}
void Game::game()
{
    for (size_t i = 0; i < 7; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            if(P[XY(i,j)].isClick(20)&&!win&&P[XY(i,j)].state==0)
            {
                if(a)
                    P[XY(i,j)].SetState(1);
                else
                    P[XY(i,j)].SetState(2);
                a=!a;

            }
            if(checkHorizontal(i,j))
            {
                win=true;
                win_pos={i,j,i+3,j};
            }
            else if(checkVertical(i,j))
            {
                win=true;
                win_pos={i,j,i,j+3};
            }
            else if(checkRightDown(i,j))
            {
                win=true;
                win_pos={i,j,i+3,j-3};
            }
            else if(checkRightUp(i,j))
            {
                win=true;;
                win_pos={i,j,i+3,j+3};
            }
            P[XY(i,j)]._draw(ren);
           
        }
        
    }
    if(win)
    {
        int x1= win_pos.x*100 +200;
        int x2= win_pos.w*100 +200;
        int y1= win_pos.y*100 +150;
        int y2= win_pos.h*100 +150;
        SDL_SetRenderDrawColor(ren,10,10,10,255);
        SDL_RenderDrawLine(ren,x1,y1,x2,y2);
    }
    
}
bool Game::checkHorizontal(uint16_t i, uint16_t j)
{
     if(i<5)
        if(P[XY(i,j)].state==P[XY(i+1,j)].state&&P[XY(i+1,j)].state==P[XY(i+2,j)].state&&P[XY(i+2,j)].state==P[XY(i+3,j)].state&&P[XY(i,j)].state!=0)
            return true;
    return false;
}
bool Game::checkVertical(uint16_t i ,uint16_t j)
{
    if(j<4)
        if(P[XY(i,j)].state==P[XY(i,j+1)].state&&P[XY(i,j+1)].state==P[XY(i,j+2)].state&&P[XY(i,j+2)].state==P[XY(i,j+3)].state&&P[XY(i,j)].state!=0)
            return true;
    return false;
}
bool Game::checkRightUp(uint16_t i ,uint16_t j)
{
    if(i<5&&j<4)
    if(P[XY(i,j)].state==P[XY(i+1,j+1)].state&&P[XY(i+1,j+1)].state==P[XY(i+2,j+2)].state&&P[XY(i+2,j+2)].state==P[XY(i+3,j+3)].state&&P[XY(i,j)].state!=0)
        return true;
    return false;
}
bool Game::checkRightDown(uint16_t i ,uint16_t j)
{
    if(j>4&&i<5)
    if(P[XY(i,j)].state==P[XY(i+1,j-1)].state&&P[XY(i,j)].state==P[XY(i+2,j-2)].state&&P[XY(i,j)].state==P[XY(i+3,j-3)].state&&P[XY(i,j)].state!=0)
        return true;
    return false;
}