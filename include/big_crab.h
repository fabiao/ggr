#pragma once

#include "sprite.h"
#include "timer_D.h"
#include "bonus.h"
#include "bullet.h"
#include "map.h"

struct SAMPLE;

class big_crab : public sprite
 {
  private:
   enum { N_BU=3 };
   enum { _NONE=0, _WAIT=1, _JUMP_UP=2, _JUMP_DOWN=3, _STOP=4, _WALK=5, _RUN=6, _SHOOT=7, _CLOSE=8, _EXPLODE=9, _HIT_GROUND=10, _OPEN=11 };
   bool have_vase;
   int dx,dy,pos_x,pos_y,scroll_x,scroll_y,gravity;
   int *ctrl_x,*ctrl_y;
   int plat_y,plat_stair,plat_wall;
   int life,energy;
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
   big_crab(const char *,int,int,BITMAP *,int i=0,big_crab *p=NULL);
   ~big_crab();
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
   void assignSample(int,big_crab *);
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