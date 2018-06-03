#pragma once

#include "sprite.h"
#include "timer_D.h"
#include "map.h"

struct BITMAP;
struct SAMPLE;

class volture : public sprite
 {
  private:
   int pos_x,pos_y,scroll_x,scroll_y,jump_y;
   int plat_y,plat_stair,plat_wall;
   int energy;
   int dx,dy;
   bool can_hit,hittable;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool stop,move,jump_up,jump_down,down,climb,fire1,fire2,fire_down,fire_up,fall,hitted,fly,dead,explode;
   timer_D *ti[5];
   SAMPLE *sound[4];
   map *plat_map;
   map *hight_map;
   map *back_map;
	
  public:
   volture(const char *,int,int,BITMAP *,int i=0,volture *p=NULL);
   ~volture();
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,volture *);
   BITMAP *getActFrameColP();
   bool inScreen();
   void setHitted(bool b);
   bool canHit();
   bool isHittable();
   int getPlatYPos();
   int getScore();
   int *getPosXP();
   int *getPosYP();
   void resetObj(bool);
   void debug();
 };