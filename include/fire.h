#pragma once

#include "map.h"
#include "timer_D.h"

struct SAMPLE;
struct BITMAP;

class fire
 {
  private:
   int start_x,start_y,pos_x,pos_y,scroll_x,scroll_y,act_x,act_y,jump_y,X,Y,_i;
   int plat_y,plat_stair,plat_wall;
   int *ctrl_x,*ctrl_y;
   int dx,dy,alpha,power;
   int r,g,b,count;
   int speed,energy;
   bool active,stop,ison,fade;
   int act_frame,act_color;
   timer_D *ti[5];
   SAMPLE *sound[4];
   //BITMAP *frame[100];
   //BITMAP *frame_col[100];
   BITMAP *out,*fire_bmp;
   int PAL[255];
   unsigned char fire_map[220][80];
   map *plat_map;
   map *hight_map;
   map *back_map;

   void setOutBitmap(BITMAP *);
 	
  public:
   fire(int,int,BITMAP *,int i=0,fire *p=NULL);
   ~fire();
   void drawSFX(int,int);
   void timeSFX();
   void platformSFX();
   void animSFX();
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,fire *);
   //BITMAP *getActFrameColP();
   bool inScreen();
   bool isOn();
   int getPlatYPos();
   int getX();
   int getY();
   void setStartX(int);
   void setStartY(int);
   void setCtrlXP(int *);
   void setCtrlYP(int *);
   void setFade(bool);
   void setPower(int);
   int *getPosXP();
   int *getPosYP();
   void resetSFX(bool);
   void debug();
 };