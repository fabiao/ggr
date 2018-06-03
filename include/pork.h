#pragma once

#include "sprite.h"
#include "timer_D.h"
#include "map.h"
#include "bullet.h"
#include "bonus.h"

struct BITMAP;
struct SAMPLE;

class pork : public sprite
 {
  private:
   enum { N_BU=3 };
   enum { _NONE=0, _JUMP_UP=1, _JUMP_DOWN=2, _STOP=3, _WALK=4, _RUN=5, _SHOOT=6, _EXPLODE=7, _HITTED=8, _HIT_GROUND=9 };
   bool have_vase;
   int dx,dy,min_x,max_x,pos_x,pos_y,scroll_x,scroll_y,gravity;
   int *ctrl_x,*ctrl_y;
   int plat_y,plat_stair,plat_wall;
   int oldaction,life,energy;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool can_hit,hittable,is_hard;
   bool hitted;
   timer_D *ti[5];
   bullet *BU[N_BU];
   SAMPLE *sound[4];
   bonus *vase;
   map *plat_map;
   map *hight_map;
   map *back_map;

   void shootBullet();
 	
  public:
   pork(const char *,int,int,BITMAP *,int i=0,pork *p=NULL);
   ~pork();
   void setMinX(int);
   void setMaxX(int);
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void setCtrlXP(int *);
   void setCtrlYP(int *);
   void loadSample(const char *,int);
   void assignSample(int,pork *);
   BITMAP *getActFrameColP();
   bullet *getBullet(int); 	 
   bool inScreen();
   int getPlatYPos();
   void attachVase(bonus *);
   void setHaveVase(bool);
   bool getHaveVase();
   int getNBullet(); 	 
   int getScore();
   int *getPosXP();
   int *getPosYP();
   void setHitted(bool);
   bool canHit();
   bool isHittable();
   bool isHard();
   void resetObj(bool);
   void debug();
 };