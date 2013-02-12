/* It's a starfield that uses SDL. 
Idea: add few lines so stars have random colours
    Input from keyboard, affect direction+speed of stars
    docs: libsdl.org/cgi/docwiki.cgi
*/
#include <stdlib.h>
#include <SDL.h>
#define MAX_STARS 100
typedef struct
{
	int x, y, speed;
} star_type;
star_type stars[MAX_STARS];

int main()
{
    int i;
    Uint8 *p;
    SDL_Surface *screen;
    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    screen = SDL_SetVideoMode(640, 480, 8, SDL_SWSURFACE);

    for(i=0;i<MAX_STARS;i++){
        stars[i].x=rand()%640;
        stars[i].y=rand()%480;
        stars[i].speed = 1 + rand()%16; // change 16 for diff effects
    }
    // Ignore all presses except window close
    for(i=0;i<SDL_NUMEVENTS;i++){
        if (i != SDL_QUIT)
            SDL_EventState(i, SDL_IGNORE);
    }
    while (SDL_PollEvent(NULL) ==0){
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,0,0)); // Paint it black

        for(i=0;i<MAX_STARS;i++){
            stars[i].x -= stars[i].speed;

            if(stars[i].x <= 0)
                stars[i].x = 640;

            p = (Uint8 *) screen->pixels + stars[i].y* screen->pitch+ stars[i].x* screen->format->BytesPerPixel;
            *p = 255;
        }
        SDL_UpdateRect(screen,0,0,0,0);
        SDL_Delay(30);
    }
    return 0;
}
