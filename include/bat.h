#pragma once

#include "sprite.h"
#include "map.h"
#include "timer_D.h"

struct SAMPLE;

class bat : public sprite {
  private:
   int pos_x,pos_y,scroll_x,scroll_y,jump_y; // start_y � la lunghezza a partire da start_x dove l'oggetto deve apparire (l'oggetto appare da start_x fino a start_x+start_y)
   int plat_y,plat_stair,plat_wall;
   int *ctrl_x,*ctrl_y;
   int energy;
   int dx,dy;
   bool can_hit,hittable;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool restart,move,hitted,dead,explode;
   timer_D *ti[5];
   SAMPLE *sound[4];
   map *plat_map;
   map *hight_map;
   map *back_map;

  public:
   bat(const char *,int,int,BITMAP *,int i=0,bat *p=NULL);
   ~bat();
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,bat *);
   BITMAP *getActFrameColP();
   bool inScreen();
   void setHitted(bool b);
   bool canHit();
   bool isHittable();
   int getPlatYPos();
   int getScore();
   void setCtrlXP(int *);
   void setCtrlYP(int *);
   int *getPosXP();
   int *getPosYP();
   void resetObj(bool);
   void debug();
 };