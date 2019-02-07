#include "defs.h"

int Game(Grid *grid,Click *click)
{
    num=0;
    SDL_WaitEvent(&event);
    switch(event.type)
    {
    case SDL_MOUSEMOTION:
        CursorX=event.motion.x;
        CursorY=event.motion.y;
    break;

    case SDL_MOUSEBUTTONDOWN:
        switch(index)
        {

            case 0:
                switch(WhereClick(click))
                {
                    case 0:
                        humanVERSUShuman=1;
                        index=1;

                        break;
                    case 1:
                        return 0;

                    default:
                        break;
                }
            case 1:
                if(InsideGrid() && EmptyCase(*grid ,rectap))
                {
                            num=num+1;
                            case1.value=0;
                            appendGrid(grid,rectap);

                            appendStorage(*grid,&caseP1,rectap.x,rectap.y);
                            if(StorageforX(caseP1,0) && StorageforX(caseP1,GRID_SIZE-1))
                            {
                                if(player==0)
                                {

                                    buffer1(grid,caseP1);
                                    index=2;
                                }

                            }
                            if(StorageforY(caseP1,0) && StorageforY(caseP1,GRID_SIZE-1) )
                            {
                                if(player==1)
                                {

                                    buffer1(grid,caseP1);
                                    index=2;
                                }
                            }
                            if(player==0)
                            {
                                player=1;
                            }
                            else
                            {
                                player=0;
                            }



        }
            break;
            case 2:
                declarewinner(player);
                end();
                index=0;
                player=0;
                initGrid(grid);
                grid->surface1=SDL_LoadBMP("Graphics/hex.bmp");
                break;
            default:
                break;
        }
    break;
    case SDL_KEYDOWN:
        keydown=event.key.keysym.sym;
        switch(keydown)
        {
            case SDLK_ESCAPE:
                return 0;
            default:
                break;

        }
        break;

    case SDL_QUIT:
        return 0;
    default:
        break;


    }
    return 1;
}


Click initclick(TTF_Font *font,char *Ftext,SDL_Rect dst, int RED,int GREEN,int BLUE)
{
    Click click;
    click.surface=SDL_CreateRGBSurface(32,dst.w,dst.h,32,0,0,0,0);
    SDL_FillRect(click.surface,NULL,SDL_MapRGB(click.surface->format,RED,GREEN,BLUE));
    click.Ftext=TTF_RenderText_Blended(font,Ftext,(SDL_Color){0,0,0});
    click.dst=dst;
    return click;
}

void initGrid(Grid *grid)
{
    int i;
    int j;
    for(i=0;i<GRID_SIZE;i++)
    {
        for(j=0;j<GRID_SIZE;j++)
        {
            grid->CELL[i][j]=0;
        }
    }
}

void blitImage(SDL_Surface *surface,SDL_Surface *surfacebis,int x,int y)
{
    SDL_Rect rectap;
    rectap.x=x;
    rectap.y=y;
    SDL_BlitSurface(surface,NULL,surfacebis,&rectap);
}

void blitClick(Click click)
{
    blitImage(click.surface,screen,click.dst.x,click.dst.y);
    blitImage(click.Ftext,click.surface,0,0);
}

int InsideGrid()
{
    SDL_Rect rectap=InsideCursorCoord();
    return (rectap.x>=0 && rectap.y>=0 && rectap.x<GRID_SIZE && rectap.x<GRID_SIZE && rectap.y<GRID_SIZE);
}

void buffer1(Grid *grid,Case case1)
{
    int i;
    int w;
    int h;
    for(i=0;i<case1.value;i++)
    {
        w=case1.x[i];
        h=case1.y[i];
        if(h==GRID_SIZE-1 || grid->CELL[w][h] != grid->CELL[w][h+1])
        {
            blitImage(Y,grid->surface1,w*30+h*15+33,h*25+43);
        }
        if(w==GRID_SIZE-1 || grid->CELL[w][h] != grid->CELL[w+1][h])
        {
            blitImage(X,grid->surface1,w*30+h*15+48,h*25+25);
        }
        if(w==0 || grid->CELL[w][h] != grid->CELL[w-1][h])
        {
            blitImage(X,grid->surface1,w*30+h*15+17,h*25+25);
        }
        if((w==GRID_SIZE-1 && h==0) || grid->CELL[w][h]!= grid->CELL[w+1][h-1])
        {
            blitImage(XY,grid->surface1,w*30+h*15+33,h*25+17);
        }
        if((w==0 && h==GRID_SIZE-1) || grid->CELL[w][h] != grid->CELL[w-1][h+1])
        {
            blitImage(XY,grid->surface1,w*30+h*15+18,h*25+43);
        }
        if(h==0 || grid->CELL[w][h] != grid->CELL[w][h-1])
        {
            blitImage(X,grid->surface1,w*30+h*15+17,h*25+18);
        }
    }
}

int EmptyCase(Grid grid,SDL_Rect rectap)
{
    return !grid.CELL[rectap.x][rectap.y];
}

void appendGrid(Grid *grid,SDL_Rect rectap)
{
    grid->CELL[rectap.x][rectap.y]=player+1;
    blitImage(player?white:black,grid->surface1,rectap.x*30+rectap.y*15+19,rectap.y*25+19);
}




int StorageforX(Case case1,int x)
{
    int i;
    for(i=0;i<case1.value;i++)
        if(case1.x[i]==x) return 1;
    return 0;

}


int StorageforY(Case case1,int y)
{
    int i;
    for(i=0;i<case1.value;i++)
        if(case1.y[i]==y) return 1;
    return 0;

}

int Storage(Case case1,int x,int y)
{
    int i;
    for(i=0;i<case1.value;i++)
        if(case1.x[i]==x && case1.y[i]==y) return 1;
    return 0;
}




void appendStorage(Grid grid , Case *case1,int x,int y)
{
    if(grid.CELL[x][y]==player+1 && !Storage(*case1,x,y))
    {
        case1->x[case1->value]=x;
        case1->y[case1->value]=y;
        case1->value++;
        if(x>0)
        {
            appendStorage(grid,case1,x+1,y);
        }
        if(y>0)
        {
            appendStorage(grid,case1,x,y-1);
        }

        if(y<GRID_SIZE-1)
        {
            appendStorage(grid,case1,x,y+1);
        }

        if(x<GRID_SIZE-1)
        {
            appendStorage(grid,case1,x+1,y);
        }

        if(y<GRID_SIZE-1 && y>0)
        {
            appendStorage(grid,case1,x-1,y+1);
        }

        if(x<GRID_SIZE-1 && x>0)
        {

            appendStorage(grid,case1,x-1,y+1);
        }
    }
}



SDL_Rect InsideCursorCoord()
{
    int x;
    int y;
    SDL_Rect rect;
    y=(CursorY-GRID_POS_Y-19);
    int i=y;
    if(y<0)
    {
        y-=25;
    }
    y/=25;
    x=(CursorX-GRID_POS_X-15*y-19);
    if(x<0)
    {
        x-=30;
    }
    if(i%25<=5)
    {
        if(x%30<13-(i*25)*2)
        {
            y--;
        }
        else if(x%30>(15+(i%25)*2))
        {
            x+=30;
            y--;
        }
    }
    x/=30;
    rect.y=y;
    rect.x=x;
    return rect;
}


void updateBuffer(Grid *grid,SDL_Rect position)
{
    if(position.x>=GRID_SIZE || position.y>=GRID_SIZE || position.x<0 || position.y<0)
    {
        grid->positionBuffer.x=-1;
    }
    else
    {
        if(!grid->CELL[position.x][position.y])
        {

            grid->surface3=buffer;
        }
        if(grid->CELL[position.x][position.y]==1)
        {
            grid->surface3=buffblack;

        }
        else
        {
            grid->positionBuffer.x=19+position.x*30+position.y*15;
            grid->positionBuffer.y=19+position.y*25;
        }
    }
}

void end()
{
    int pursue;
    SDL_Event event;
    pursue=1;
    while(pursue)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            pursue=0;
            exit(0);
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                pursue=0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {

                    case SDL_BUTTON_RIGHT:
                        pursue=0;
                        break;
                }
            default :
                break;
            }
        }
    }
}

void Cursor()
{
    SDL_ShowCursor(0);
    if(CursorX>0 && CursorY>0 && CursorX<ScreenLength && CursorY<ScreenWidth)
    {

        if(index!=2)
        {
            blitImage(IMG_Load("Graphics/cursor.png"),screen,CursorX,CursorY);
        }
        else
        {
            SDL_ShowCursor(1);
        }

    }

}

int upClick(Click click)
{
    int x=click.dst.x;
    int y=click.dst.y;
    int h=click.dst.h;
    int w=click.dst.w;

    int boolreturn;
    if(CursorX>x && CursorX<x+w && CursorY>y && CursorY<y+h)
    {
        boolreturn=1;
    }
    else
    {
        boolreturn=0;
    }

    return boolreturn;
}

int WhereClick(Click *click)
{
    int i=0;
    for(i=0;i<2;i++)
    {
        if(upClick(click[i]))
        {
            return i;
        }
    }
    return -1;
}

void declarewinner(int player)
{
    TTF_Init();
    SDL_Rect rect;
    rect.x=300;
    rect.y=30;
    TTF_Font *font=TTF_OpenFont("TTF/georgia.tf",50);
    SDL_BlitSurface(TTF_RenderText_Blended(font,player? "Player with Color Black wins":"Player with Color White wins",(SDL_Color){0,0,0}),NULL,screen,&rect);
    SDL_Flip(screen);
    rect.x=10; rect.y=500;
    TTF_Font *font1= TTF_OpenFont("Polices/georgia.ttf",30);
    SDL_BlitSurface(TTF_RenderText_Blended(font1,"Click ont the left button of the mouse to return to the main menu",(SDL_Color){0,0,0}),NULL,screen,&rect);
    rect.y=550;
    SDL_BlitSurface(TTF_RenderText_Blended(font1,"You can Quit the game with : ESC",(SDL_Color){0,0,0}),NULL,screen,&rect);
    SDL_Flip(screen);
    TTF_CloseFont(font);
    TTF_CloseFont(font1);
    TTF_Quit();
}



