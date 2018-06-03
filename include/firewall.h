#pragma once

#include "sprite.h"
#include "map.h"
#include "timer_D.h"

struct SAMPLE;
struct BITMAP;

class firewall : public sprite
 {
  private:
   int coun,maxy,pos_x,pos_y,scroll_x,scroll_y,max_y,min_y;
   int plat_y,plat_stair,plat_wall;
   int dx,dy;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool stop,move,jump_up,jump_down,down,climb,fire1,fire2,fire_down,fire_up,fall,turn;
   timer_D *ti[5];
   int count,max_count;
   SAMPLE *sound[4];
   map *plat_map;
   map *hight_map;
   map *back_map;
 	
  public:
   firewall(const char *,int,int,int,int,BITMAP *,int i=0,firewall *p=NULL);
   ~firewall();
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setMaxY(int);
   void setCount(int);
   void setMaxCount(int);
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,firewall *);
   BITMAP *getActFrameColP();
   bool inScreen();
   int getPlatYPos();
   int *getPosXP();
   int *getPosYP();
   void resetObj(bool);
   void debug();
 };