#include "sprite.h"
#include "util.h"
#include <allegro.h>
#include <cstdio>

sprite::sprite(const char *filename,BITMAP *bmp,int sx,int sy,int i,sprite *p)
 {
  index = i;
  loadSprite(filename,p);
  setScreen(bmp);
  start_x = sx; start_y = sy;
 }

sprite::~sprite() { }

void sprite::loadSprite(const char *filename,sprite *p)
 {
  if(!index)
   {
    loadData(filename);
    loadFrames(filename);
   }
  else
   {
	rows    = p->getRows();
	columns = p->getColumns();
	width   = p->getWidth();
    height  = p->getHeight();
    frames           = p->frames;
    frames_collision = p->frames_collision;
   }
 }

void sprite::loadData(const char *filename)
 {
  FILE *fd;
  char str[255];

  fd = fopen(strcat(strcpy(str,filename),".txt"),"r");
  if(!fd) { allegro_message("File \"%s\" not found.\n\nGame closed!",str); exit(0); }
  fscanf(fd,"%d%s%d%s%d%s%d",&rows,str,&columns,str,&width,str,&height);
  fclose(fd);
 }

void sprite::loadFrames(const char *filename)
 {
  BITMAP *aux;
  char str[255];

  frames           = (BITMAP **)malloc(sizeof(BITMAP *)*(rows*columns));
  frames_collision = (BITMAP **)malloc(sizeof(BITMAP *)*(rows*columns));

  aux = load_bmp(strcat(strcpy(str,filename),".bmp"),NULL);
  if(!aux) { allegro_message("File \"%s\" not found.\n\nGame closed!",str); exit(0); }
  for(int i=0;i<rows;i++)
   for(int j=0;j<columns;j++)
    {
     frames[j+columns*i]           = create_bitmap(width,height);
     frames_collision[j+columns*i] = create_bitmap_ex(8,width,height);
     //blit(aux,frames[j+columns*i],width*j+j,height*i+i,0,0,frames[j+columns*i]->w,frames[j+columns*i]->h);
     blit(aux,frames[j+columns*i],width*j,height*i,0,0,frames[j+columns*i]->w,frames[j+columns*i]->h);
     clear_to_color(frames_collision[j+columns*i],0);
     for(int h=0;h<frames[j+columns*i]->h;h++)
      for(int w=0;w<frames[j+columns*i]->w*4;w+=4)
       if(makecol32(frames[j+columns*i]->line[h][w+2],
                    frames[j+columns*i]->line[h][w+1],
                    frames[j+columns*i]->line[h][w]) != 16711935) frames_collision[j+columns*i]->line[h][w>>2] = 1;
    }
  destroy_bitmap(aux);
 }

void sprite::setStartX(int sx)      { start_x = sx; }

void sprite::setStartY(int sy)      { start_y = sy; }

void sprite::setX(int x)            { X = x; }

void sprite::setY(int y)            { Y = y; }

void sprite::setCurrentFrame(int f) { act_frame = f; }

void sprite::setScreen(BITMAP *bmp) { screen = bmp; }

int sprite::getRows()         { return rows;    }

int sprite::getColumns()      { return columns; }

int sprite::getWidth()        { return width;   }

int sprite::getHeight()       { return height;  }

int sprite::getX()            { return X; }

int sprite::getY()            { return Y; }

int sprite::getCurrentFrame() { return act_frame; }

BITMAP *sprite::getFrame(int i) { return frames[i]; }

bool sprite::isEnabled() { return enabled; }
