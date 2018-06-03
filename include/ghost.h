#pragma once

#include "sprite.h"
#include "timer_D.h"
#include "map.h"

struct BITMAP;
struct SAMPLE;

class ghost : public sprite
 {
  private:
   int pos_x,pos_y,scroll_x,scroll_y,jump_y; // start_y � la lunghezza a partire da start_x dove l'oggetto deve apparire (l'oggetto appare da start_x fino a start_x+start_y)
   int plat_y,plat_stair,plat_wall;
   int *ctrl_x,*ctrl_y;
   int energy,speed;
   int dx,dy;
   bool can_hit,hittable;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool restart,move,near,far,hitted,dead,explode;
   timer_D *ti[5];
   SAMPLE *sound[4];
   map *plat_map;
   map *hight_map;
   map *back_map;

  public:
   ghost(const char *,int,int,BITMAP *,int i=0,ghost *p=NULL);
   ~ghost();
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,ghost *);
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