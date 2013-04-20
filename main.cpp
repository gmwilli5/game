#include "game.h"
int Game::execute()
{
    SDL_Event Event;
    if((innit()==false)){return -1;};
    while(running){
        while(SDL_PollEvent(&Event)) {
            event(&Event);
        }
        loop();
        render();
    }
    return 0;
}
int main()
{
    Game game;
    int g=game.execute();
    return g;
}
