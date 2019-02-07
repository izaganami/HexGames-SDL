#include "structs.h"






int CursorX;
int CursorY;
int player;
int humanVERSUShuman;
int scale;



SDL_Event event;
int num;

SDL_Rect title1;
SDL_Rect title2;
SDL_Rect InsideCursorCoord();
SDL_Rect rectap;
SDL_Rect temp;
SDL_Rect dst2;
SDL_Surface *screen;
SDL_Surface *black;
SDL_Surface *white;
SDL_Surface *buffer;
SDL_Surface *background;
SDL_Surface *buffwhite;
SDL_Surface *buffblack;
SDL_Surface *X;
SDL_Surface *XY;
SDL_Surface *Y;
SDLKey keydown;

TTF_Font *menu;
TTF_Font *font;

Case case1;
Case caseP1;
Case caseP2;
Grid grid;
Click click[2];
Click initclick(TTF_Font *font,char *Ftext,SDL_Rect dst,int RED,int GREEN,int BLUE);








