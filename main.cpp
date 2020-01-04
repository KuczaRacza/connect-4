#include"game.h"
#include <cstdio>
#include<iostream>
#define DEBUG true
GlobalInfo global;
int main(int argc, char *argv[]) {
    SDL_Window *win=NULL;
    SDL_Renderer *renderer=NULL;
    int posX = 100, posY = 100, width = 1000, height = 800;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    win = SDL_CreateWindow("open connect 4", posX, posY, width, height, 0);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG);
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
   
   
    Game g(renderer,&global);


    while (1) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }
        SDL_SetRenderDrawColor(renderer,90,150,140,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        global.setDeltaTime();
        global.lastClick+=global.deltaTime;
        if(DEBUG)
        {
            
            std::cout<<"frameTime "<<global.deltaTime<<" | Debug"<<'\n';
        }
        g.game();
        SDL_RenderPresent(renderer);
        SDL_Delay(global.getSyncTime());
        
    }

   
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}
