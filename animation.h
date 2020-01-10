#include"panel.h"
#include<math.h>
class Animation
{
    public:
    Animation(SDL_Renderer * w,GlobalInfo * g);
    SDL_Renderer * win;
    float hovertime;
    SDL_Color c;
    GlobalInfo * global;
    void verticalHower(SDL_Rect position);
    SDL_Rect _r;
    void update();
    void hoverAnimation();
    void hoverAnimationGradient(SDL_Rect position);
    void renderTilesForeground(Panel *p);
    void renderTilesBackground(Panel *p);
    static uint16_t XY(uint16_t i,uint16_t j);
};