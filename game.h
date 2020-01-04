#include"panel.h"
class Game
{
    public:
    Game(SDL_Renderer * r,GlobalInfo *g);
    SDL_Renderer * ren;
    GlobalInfo * global;
    Panel *P;
    void test();
    bool a=false;;
    bool win=false;
    SDL_Rect win_pos;
    void game();
    bool checkHorizontal(uint16_t i,uint16_t j);
    bool checkVertical(uint16_t i,uint16_t j);
    bool checkRightUp(uint16_t i ,uint16_t j);
    bool checkRightDown(uint16_t i ,uint16_t j);
    static uint16_t XY(uint16_t x,uint16_t y);
    uint16_t setLowest(uint16_t x);
};