#include "defs.h"

int main(int argc, char *argv[])
{
    SDL_ShowCursor(SDL_DISABLE);
    rectap=InsideCursorCoord();
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        fprintf(stderr,"couldn t load SDL video : %s\n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    screen=SDL_SetVideoMode(ScreenLength,ScreenWidth,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(!screen)
    {
        fprintf(stderr, "couldn t load image %s\n",SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
    }
    initGrid(&grid);
    background=IMG_Load("Graphics/background .jpg");
    TTF_Init();
    menu=TTF_OpenFont("TTF/georgia.ttf",50);
    TTF_SetFontStyle(menu, TTF_STYLE_BOLD);
    title1.x=150;
    title1.y=200;
    title1.w=460;
    title1.h=70;
    click[0]=initclick(menu,"HumanVSHuman",title1,180,180,150);
    title2.x=250;
    title2.y=300;
    title2.w=260;
    title2.h=70;
    click[1]=initclick(menu,"   QUIT",title2,180,180,150);
    SDL_Rect title0;
    title0.x=250;
    title0.y=100;
    title0.w=300;
    title0.h=80;


    SDL_WM_SetCaption("HEX GAME",NULL);
    grid.surface1=SDL_LoadBMP("Graphics/hex.bmp");
    grid.surface2=SDL_LoadBMP("Graphics/hex.bmp");
    SDL_SetColorKey(grid.surface1,SDL_SRCCOLORKEY,SDL_MapRGB(grid.surface1->format,20,150,150));
    SDL_SetColorKey(grid.surface2,SDL_SRCCOLORKEY,SDL_MapRGB(grid.surface2->format,20,150,150));
    black=IMG_Load("Graphics/black.png");
    white=IMG_Load("Graphics/white.png");
    buffer=IMG_Load("Graphics/buffer.png");
    buffblack=IMG_Load("Graphics/bufferblack.png");
    buffwhite=IMG_Load("Graphics/bufferwhite.png");
    X=IMG_Load("Graphics/x.png");
	Y=IMG_Load("Graphics/y.png");
	XY=IMG_Load("Graphics/xy.png");
	player=0;
	index=0;
	while(Game(&grid,click))
    {
        if(index==0)
        {
            blitImage(background,screen,0,0);
            menu=TTF_OpenFont("TTF/ALGER.ttf",70);
            SDL_BlitSurface(TTF_RenderText_Blended(menu," MENU ",(SDL_Color){255,255,255}),NULL,screen,&title0);
            blitClick(click[0]);
            blitClick(click[1]);
        }
        else
        {
            SDL_SetColorKey(grid.surface1,SDL_SRCCOLORKEY,SDL_MapRGB(grid.surface1->format,150,150,150));
            SDL_SetColorKey(grid.surface2,SDL_SRCCOLORKEY,SDL_MapRGB(grid.surface2->format,150,150,150));
            SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
            update(&grid);
            blitImage(grid.surface1,grid.surface2,0,0);

        }
        Cursor();
        SDL_Flip(screen);

    }
    SDL_FreeSurface(screen);
	SDL_FreeSurface(white);
	SDL_FreeSurface(black);
	TTF_CloseFont(menu);
	SDL_FreeSurface(buffer);
	SDL_FreeSurface(buffwhite);
	SDL_FreeSurface(buffblack);
	TTF_Quit();
	SDL_Quit();
	return 0;




}

void update(Grid *grid)
{
	updateBuffer(grid,InsideCursorCoord());
	if(grid->positionBuffer.x!=-1 && index!=2) blitImage(grid->surface3,grid->surface2,grid->positionBuffer.x, grid->positionBuffer.y);
    blitImage(grid->surface2,screen,GRID_POS_X, GRID_POS_Y);
}
