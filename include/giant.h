#pragma once

#include "sprite.h"
#include "timer_D.h"
#include "map.h"
#include "bullet.h"

struct BITMAP;
struct SAMPLE;

class giant : public sprite
 {
  private:
   enum { N_BU=4 };
   int max_x,min_x,pos_x,pos_y,scroll_x,scroll_y,jump_y;
   int plat_y,plat_stair,plat_wall;
   int *ctrl_x,*ctrl_y;
   int energy;
   int dx,dy;
   bool can_hit,hittable;
   bool near,side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool stop,move,fire,open,hitted,first_hit,dead,explode;
   timer_D *ti[5];
   bullet *BU[N_BU];
   SAMPLE *sound[4];
   map *plat_map;
   map *hight_map;
   map *back_map;

   void shootBullet();
 	
  public:
   giant(const char *,int,int,BITMAP *,int i=0,giant *p=NULL);
   ~giant();
   void setMaxX(int);
   void setMinX(int);
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,giant *);
   BITMAP *getActFrameColP();
   bullet *getBullet(int);
   bool inScreen();
   void setHitted(bool b);
   bool canHit();
   bool isHittable();
   int getPlatYPos();
   int getNBullet();
   void setCtrlXP(int *);
   void setCtrlYP(int *);
   int *getPosXP();
   int *getPosYP();
   int getScore();
   void resetObj(bool);
   void debug();
 };