#pragma once

#include "timer_D.h"
#include "map.h"

struct BITMAP;
struct SAMPLE;

class thunder
 {
  private:
 	 enum { _NONE=0, _FLASH=1, _FADE=2 };
 	 int action,start_x,start_y,pos_x,pos_y,X,Y,_i;
 	 int *ctrl_x,*ctrl_y;
 	 bool active;
 	 int alpha,act_frame,c0,c1,c2,start_deep;
 	 timer_D *ti[5];
 	 SAMPLE *sound[4];
 	 BITMAP *out,*aux_bmp;

 	 void setOutBitmap(BITMAP *);
 	
 	public:
 	 thunder(int,int,BITMAP *,int i=0,thunder *p=NULL);
 	 ~thunder();
 	 void drawSFX(int,int);
 	 void timeSFX();
 	 void animSFX();
 	 void drawThunder(int,int,int,int,int,int,int,int);
 	 void setPlatformMap(map *p);
 	 void setHightMap(map *p);
 	 void setBackgroundMap(map *p);
   void setScrollSpeed(int);
   void setDeep(int);
   void setWaterLen(int);
   void setWaveSpeed(int);
 	 void loadSample(const char *,int);
 	 void assignSample(int,thunder *);
 	 bool inScreen();
 	 int getPlatYPos();
 	 int getX();
 	 int getY();
 	 void setStartX(int);
 	 void setStartY(int);
 	 void setCtrlXP(int *);
   void setCtrlYP(int *);
 	 int *getPosXP();
 	 int *getPosYP();
 	 void resetSFX(bool);
 	 void debug();
 };