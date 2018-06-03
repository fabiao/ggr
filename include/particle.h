#pragma once

#include "timer_D.h"
#include "map.h"

struct BITMAP;
struct SAMPLE;

class particle
 {
  private:
   enum { _COL=52, _ROW=1, _XPIX=22, _YPIX=22 };
   enum { _NONE=0, _READY=1, _RUN=2 };
   int dx,dy,start_x,start_y,pos_x,pos_y,scroll_x,scroll_y,gravity,X,Y,_i;
   int *ctrl_x,*ctrl_y;
   int plat_y,plat_stair,plat_wall;
   int act_frame,action,life,alpha;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool can_hit,hittable,is_hard;
   bool active,hitted;
   timer_D *ti[5];
   SAMPLE *sound[4];
   BITMAP *frame[_COL*_ROW];
   BITMAP *frame_col[_COL*_ROW];
   BITMAP *out;
   map *plat_map;
   map *hight_map;
   map *back_map;

   void loadSFXFrames(const char *);
   void assignSFXFrame(particle *);
   void setOutBitmap(BITMAP *);
 	
  public:
   particle(const char *,int,int,BITMAP *,int i=0,particle *p=NULL);
   ~particle();
   void setStartX(int);
   void setStartY(int);
   bool isActive();
   void drawSFX(int,int);
   void timeSFX();
   void platformSFX();
   void animSFX();
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void setCtrlXP(int *);
   void setCtrlYP(int *);
   void loadSample(const char *,int);
   void assignSample(int,particle *);
   BITMAP *getActFrameColP();
   bool inScreen();
   int getPlatYPos();
   int getX();
   int getY();
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