#pragma once

#include "sprite.h"
#include "bullet.h"

struct SAMPLE;
struct BITMAP;

class clam : public sprite
 {
  private:
   enum { N_BU=3 };
   int pos_x,pos_y,scroll_x,scroll_y,jump_y;
   int plat_y,plat_stair,plat_wall;
   int *ctrl_x,*ctrl_y;
   int energy;
   int dx,dy;
   bool can_hit,hittable;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool stop,move,fire,open,hitted,dead,explode;
   timer_D *ti[5];
   bullet *BU[N_BU];
   SAMPLE *sound[4];
   map *plat_map;
   map *hight_map;
   map *back_map;

   void shootBullet();
 	
  public:
   clam(const char *,int,int,BITMAP *,int i=0,clam *p=NULL);
   ~clam();
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,clam *);
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
   void setSide(bool);
   int *getPosXP();
   int *getPosYP();
   int getScore();
   void resetObj(bool);
   void debug();
 };