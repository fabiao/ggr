#pragma once

#include "sprite.h"
#include "timer_D.h"
#include "map.h"

struct BITMAP;
struct SAMPLE;

class rockfall : public sprite
 {
  private:
   enum { _NONE=0, _SHAKE=1, _FALL=3, _SLAM=4, _BOUNCE=5 };
   int afr,coun,maxy,pos_x,pos_y,scroll_x,scroll_y,max_y,min_y;
   int plat_y,plat_stair,plat_wall;
   int dx,dy;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool jump_up,jump_down,climb,fall;
   timer_D *ti[5];
   int count;
   SAMPLE *sound[4];
   map *plat_map;
   map *hight_map;
   map *back_map;
 	
  public:
   rockfall(const char *,int,int,int,int,BITMAP *,int fr=0,int i=0,rockfall *p=NULL);
   ~rockfall();
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setMaxY(int);
   void setCount(int);
   void setActualFrame(int);
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,rockfall *);
   BITMAP *getActFrameColP();
   bool inScreen();
   int getPlatYPos();
   int *getPosXP();
   int *getPosYP();
   void resetObj(bool);
   void debug();
 };