#pragma once

#include "sprite.h"
#include "timer_D.h"
#include "map.h"
#include "bonus.h"

struct BITMAP;
struct SAMPLE;

class skeleton : public sprite
 {
  private:
   bool have_vase;
   int pos_x,pos_y,scroll_x,scroll_y,jump_y;
   int plat_y,plat_stair,plat_wall;
   int dx,dy;
   int life,speed,slow;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool can_hit,hittable;
   bool stop,move,jump_up,jump_down,down,climb,fire1,fire2,fire_down,fire_up,fall,turn,rise,unrise,hitted,explode;
   timer_D *ti[5];
   SAMPLE *sound[4];
   bonus *vase;
   map *plat_map;
   map *hight_map;
   map *back_map;

  public:
   skeleton(const char *,int,int,BITMAP *,int i=0,skeleton *p=NULL);
   ~skeleton();
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,skeleton *);
   BITMAP *getActFrameColP();
   bool inScreen();
   int getPlatYPos();
   void attachVase(bonus *);
   void setHaveVase(bool);
   bool getHaveVase(); 	 
   int getScore();
   int *getPosXP();
   int *getPosYP();
   void setHitted(bool);
   bool canHit();
   bool isHittable();
   void resetObj(bool);
   void debug();
 };