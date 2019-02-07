#include "variables.h"



typedef struct
{
    SDL_Surface *surface1;
    SDL_Surface *surface2;
    SDL_Surface *surface3;
    int CELL[GRID_SIZE][GRID_SIZE];
    SDL_Rect positionBuffer;
}Grid;


typedef struct
{
    SDL_Surface *surface;
    SDL_Surface *Ftext;
    SDL_Rect dst;
}Click;


typedef struct
{
    int x[41];
    int y[41];
    int value;
}Case;


typedef struct
{
    int x;
    int y;
}Emptycase;





int index;
extern void Cursor();
extern void end();
extern void blitImage(SDL_Surface *surface,SDL_Surface *surfacebis,int x,int y);
extern void blitClick(Click click);
extern void update(Grid *grid);
extern void buffer1(Grid *grid,Case case1);
extern void updateBuffer(Grid *grid,SDL_Rect position);
extern void declarewinner(int player);
extern int InsideGrid();
extern void initGrid(Grid *grid);
extern int StorageforX(Case case1,int x);
extern int StorageforY(Case case1,int y);
extern int Storage(Case case1,int x,int y);
extern void appendStorage(Grid grid,Case *case1,int x,int y);
extern int EmptyCase(Grid grid,SDL_Rect rectap);
extern void appendGrid(Grid *grid,SDL_Rect rectap);
extern int upClick(Click click);
extern int WhereClick(Click *click);
extern int Game(Grid *grid,Click *click);








