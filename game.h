#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SDL/SDL.h>
#include <vector>
#include "structs.h"
using namespace std;
class Game {
    private:
        bool running;
        bool left;
        bool right;
        bool up;
        bool down;
        bool shoot;
        bool bs;
        bool enemy_kill;
        bool enemy_kill1;
        bool enemy_kill2;
        bool enemy_kill3;
        bool enemy_kill4;
        bool enemy_kill5;
        bool enemy_kill6;
        bool enemy_kill7;
        bool enemy_kill8;
        bool enemy_kill9;
        int bpx;
        int bpy;
        int px;
        int py;
        int epx;
        int epx1;
        int epx2;
        int epx3;
        int epx4;
        int epx5;
        int epx6;
        int epx7;
        int epx8;
        int epx9;
        int epy;
        int epy2;
        int enemy_loop_count;
        int enemy_count;
        int bullet_count;
        int bbby;
        int bbbx;
        SDL_Surface* screen;
        SDL_Surface* background;
        SDL_Surface* player;
        SDL_Surface* enemy;
        SDL_Surface* bullet;
        vector<bullets> bullets_on_screen;
        vector<enemies> enemies_on_screen;
    public:

        int OnExecute();
        void render();
        void keydown(SDLKey sym, SDLMod mod, Uint16 unicode);

    public:
        Game();
        int execute();
        void loop();
        void event(SDL_Event * Event);
        void cleanup();
        bool innit();
        static bool draw(SDL_Surface* dest, SDL_Surface* src, int X, int Y);
};
#endif // GAME_H_INCLUDED
