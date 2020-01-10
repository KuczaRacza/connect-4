
#include"animation.h"
class Game:public Animation
{  
    public:
    Game(SDL_Renderer * r,GlobalInfo *g);
    SDL_Renderer * ren;
    GlobalInfo * global;
    Panel *P;
    bool a=false;
    bool win=false;
    SDL_Rect win_pos;
    void game();
    bool checkHorizontal(uint16_t i,uint16_t j);
    bool checkVertical(uint16_t i,uint16_t j);
    bool checkRightUp(uint16_t i ,uint16_t j);
    bool checkRightDown(uint16_t i ,uint16_t j);
  
    void restart();
    Button reset;
    uint16_t setLowest(uint16_t x);
    void columnAnimation();
};