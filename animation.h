#include"panel.h"
#include<math.h>
#include<SDL2/SDL_ttf.h>
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
    TTF_Font * FontFile = NULL;
    const char * font = "./Lato-Regular.ttf";
    void update();
    void hoverAnimation();
    void hoverAnimationGradient(SDL_Rect position);
    void renderTilesForeground(Panel *p);
    void renderTilesBackground(Panel *p);
    void renderTexts();
    void makeText(SDL_Rect _pos, SDL_Color _color,std::string message);
    static uint16_t XY(uint16_t i,uint16_t j);
};