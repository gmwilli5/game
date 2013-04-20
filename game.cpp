#include "SDL/SDL.h"
#include "game.h"
#include "SDL/SDL_image.h"
#include <iostream>
using namespace std;
//loads all the images to surfaces
bool Game::innit()
{
    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
    cout<<"8"<<endl;
    if((screen=SDL_SetVideoMode(600, 400, 32, SDL_SWSURFACE))==NULL){return false;}
    if(((background=SDL_LoadBMP("background.bmp"))==NULL)){return false;}
    if(((player=SDL_LoadBMP("player.bmp"))==NULL)){return false;}
    if(((enemy=SDL_LoadBMP("enemy.bmp"))==NULL)){return false;}
    if(((bullet=SDL_LoadBMP("bullet.bmp"))==NULL)){return false;}
    return true;
}
//draws the surfaces too the screen
void Game::render()
{
    draw(screen, background, 0, 0);
    bullets b1;
    if(bullet_count>1){
        for(int iii=0; iii<(bullet_count-1); iii++){
            b1=bullets_on_screen[iii];
            draw(screen, bullet ,b1.x_coor,b1.y_coor);
        }
    }
    draw(screen, player,px, py);
    if(enemy_kill==false){
        draw(screen, enemy,epx, epy);
    }
    if(enemy_kill1==false){
        draw(screen, enemy, epx1, epy);
    }
    if(enemy_kill2==false){
        draw(screen, enemy, epx2, epy);
    }
    if(enemy_kill3==false){
        draw(screen, enemy, epx3, epy);
    }
    if(enemy_kill4==false){
        draw(screen, enemy, epx4, epy);
    }
    if(enemy_kill5==false){
        draw(screen, enemy, epx5, epy2);
    }
    if(enemy_kill6==false){
        draw(screen, enemy, epx6, epy2);
    }
    if(enemy_kill7==false){
        draw(screen, enemy, epx7, epy2);
    }
    if(enemy_kill8==false){
        draw(screen, enemy, epx8, epy2);
    }
    if(enemy_kill9==false){
        draw(screen, enemy, epx9, epy2);
    }

    SDL_Flip(screen);
}
//initilizes all the game class variables
Game::Game()
{
    running=true;
    enemy_kill=false;
    py=380;
    px=300;
    epx=100;
    epx1=200;
    epx2=300;
    epx3=400;
    epx4=500;
    epx5=100;
    epx6=200;
    epx7=300;
    epx8=400;
    epx9=500;
    epy=100;
    epy2=200;
    bpx=px;
    bpy=py;
    enemy_loop_count=0;
    enemy_count=1;
    bullet_count=1;
    up=false;
    down=false;
    left=false;
    right=false;
    shoot=false;
    bs=false;
}
//draw function used in the render function
 bool Game::draw(SDL_Surface* dest, SDL_Surface* src, int X, int Y)
{
    if(dest == NULL || src == NULL) {
        return false;
    }
    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    SDL_BlitSurface(src, NULL, dest, &DestR);
    //cout<<"27"<<endl;
    return true;
}
//checks for keyboard input
void Game::event(SDL_Event * Event)
{
    if(Event->type == SDL_QUIT) {
       /* bullets b;
       for(int iii=0; iii<(bullet_count-1); iii++){
           b= bullets_on_screen[iii];
            //cout<<"x: "<<b.x_coor<<" y: "<<b.y_coor<<endl;
       }*/
        SDL_FreeSurface(screen);
        SDL_FreeSurface(background);
        SDL_FreeSurface(enemy);
        SDL_FreeSurface(player);
        SDL_FreeSurface(bullet);
        running = false;
    }
   if(Event->type==SDL_KEYDOWN){
        if(Event->key.keysym.sym==SDLK_UP){up=true;}
        if(Event->key.keysym.sym==SDLK_DOWN){down=true;}
        if(Event->key.keysym.sym==SDLK_LEFT){left=true;}
        if(Event->key.keysym.sym==SDLK_RIGHT){right=true;}
        if(Event->key.keysym.sym==SDLK_SPACE){shoot=true;}
   }
   if(Event->type==SDL_KEYUP){
        if(Event->key.keysym.sym==SDLK_UP){up=false;}
        if(Event->key.keysym.sym==SDLK_DOWN){down=false;}
        if(Event->key.keysym.sym==SDLK_LEFT){left=false;}
        if(Event->key.keysym.sym==SDLK_RIGHT){right=false;}
   }
}
//the loop that actually controls the players
void Game::loop()
{
    if(up==true){
        py-=1;
    }
    if(py==390){
        down=false;
    }
    if(down==true){
        py+=1;
    }
    if(left==true){
        px-=1;
    }
    if(right==true){
        px+=1;
    }
    if(px==601){
        px=0;
    }
    if(px==-10){
        px=600;
    }
    if(py==-10){
        py=390;
    }
    if(epx==-10){
        epx=580;
   }
   if(epx1==-10){
        epx1=580;
   }
   if(epx2==-10){
        epx2=580;
   }
   if(epx3==-10){
        epx3=580;
   }
   if(epx4==-10){
        epx4=580;
   }
   if(epx5==600){
        epx5=0;
   }
   if(epx6==600){
        epx6=0;
   }
   if(epx7==600){
        epx7=0;
   }
   if(epx8==600){
        epx8=0;
   }
   if(epx9==600){
        epx9=0;
   }
    //enemies e;enemy_loop_count==2
    if(true){
        epx+=-1;
        epx1+=-1;
        epx2+=-1;
        epx3+=-1;
        epx4+=-1;
        epx5+=1;
        epx6+=1;
        epx7+=1;
        epx8+=1;
        epx9+=1;
        enemy_loop_count=0;
        /*for(int iii=0; iii<enemy_count; iii++){
            e=enemies_on_screen[iii];
            if(e.left==true){
                e.x+=-1;
            }
        }
        enemy_loop_count=0;*/
    }
    enemy_loop_count+=1;

    bpy=py;
    bpx=px;
    if(shoot==true){
        bullets_on_screen.push_back(bullets{bpx,bpy,10});
        bullet_count+=1;
        shoot=false;
    }
    bullets b;
    //int y_coor;
    if(bullet_count>1){
        for(int iii=0; iii<(bullet_count-1); iii++){
            if(b.y_coor<-10){
                bullets_on_screen.erase(bullets_on_screen.begin()+iii);
                bullet_count-=1;
            }
            else{
                b=bullets_on_screen[iii];
                bbby=b.y_coor;
                bbbx=b.x_coor;
                bullets_on_screen.erase(bullets_on_screen.begin()+iii);
                bbby-=5;
                bullets_on_screen.push_back(bullets{bbbx,bbby,10});
                if(bbbx>epx && bbbx<(epx+30) && bbby<(epy) && bbby>=(epy-20)){
                    enemy_kill=true;
                }
                if(bbbx>epx1 && bbbx<(epx1+30) && bbby<(epy) && bbby>=(epy-20)){
                    enemy_kill1=true;
                }
                if(bbbx>epx2 && bbbx<(epx2+30) && bbby<(epy) && bbby>=(epy-20)){
                    enemy_kill2=true;
                }
                if(bbbx>epx3 && bbbx<(epx3+30) && bbby<(epy) && bbby>=(epy-20)){
                    enemy_kill3=true;
                }
                if(bbbx>epx4 && bbbx<(epx4+30) && bbby<(epy) && bbby>=(epy-20)){
                    enemy_kill4=true;
                }
                if(bbbx>epx5 && bbbx<(epx5+30) && bbby<(epy2) && bbby>=(epy2-20)){
                    enemy_kill5=true;
                }
                if(bbbx>epx6 && bbbx<(epx6+30) && bbby<(epy2) && bbby>=(epy2-20)){
                    enemy_kill6=true;
                }
                if(bbbx>epx7 && bbbx<(epx7+30) && bbby<(epy2) && bbby>=(epy2-20)){
                    enemy_kill7=true;
                }
                if(bbbx>epx8 && bbbx<(epx8+30) && bbby<(epy2) && bbby>=(epy2-20)){
                    enemy_kill8=true;
                }
                if(bbbx>epx9 && bbbx<(epx9+30) && bbby<(epy2) && bbby>=(epy2-20)){
                    enemy_kill9=true;
                }

            }
        }
    }
}
