#pragma once

#include "sprite.h"
#include "timer_D.h"
#include "map.h"
#include "bonus.h"

struct BITMAP;
struct SAMPLE;

class red_arremer_king : public sprite
 {
  private:
   int pos_x,pos_y,scroll_x,scroll_y,jump_y;
   int plat_y,plat_stair,plat_wall;
   int *ctrl_x,*ctrl_y;
   int dx,dy;
   int speed,energy;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool can_hit,hittable;
   bool stop,move,fly,dead,attack,jump_up,jump_down,down,fire1,fire2,fall,turn,rise,unrise,hitted,explode,sleep;
   timer_D *ti[5];
   SAMPLE *sound[4];
   map *plat_map;
   map *hight_map;
   map *back_map;
   bonus *exit_key;
	
  public:
   red_arremer_king(const char *,int,int,BITMAP *,int i=0,red_arremer_king *p=NULL);
   ~red_arremer_king();
   void setExitKeyP(bonus *);
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,red_arremer_king *);
   BITMAP *getActFrameColP();
   bool inScreen();
   int getPlatYPos();
   void setCtrlXP(int *);
   void setCtrlYP(int *);
   int *getPosXP();
   int *getPosYP();
   int getScore();
   void setHitted(bool);
   bool canHit();
   bool isHittable();
   void resetObj(bool);
   void debug();
 };