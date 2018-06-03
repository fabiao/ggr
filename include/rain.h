#pragma once

#include "timer_D.h"
#include "map.h"
#include "bullet.h"

struct BITMAP;
struct SAMPLE;

class rain
 {
 	private:
 	 int start_x,start_y,pos_x,pos_y,scroll_x,scroll_y,act_x,act_y,jump_y,X,Y,_i;
 	 int plat_y,plat_stair,plat_wall;
 	 int *ctrl_x,*ctrl_y;
 	 int dx,dy,alpha;
 	 int r,g,b,count;
 	 int *RX,*RY,*RS,num_drops;
 	 bool active,stop,ison,type,raining;
 	 int max_drops;
 	 int act_frame,act_color;
 	 timer_D *ti[5];
 	 SAMPLE *sound[4];
 	 //BITMAP *frame[100];
 	 //BITMAP *frame_col[100];
 	 BITMAP *out,*rain_bmp;
 	 int TRA,COL1,COL2,COL3;
 	 unsigned char rain_map[640][50];
 	 map *plat_map;
 	 map *hight_map;
 	 map *back_map;

 	 void setOutBitmap(BITMAP *);
 	
 	public:
 	 rain(int,int,BITMAP *,int i=0,rain *p=NULL);
 	 ~rain();
 	 void drawSFX(int,int);
 	 void timeSFX();
 	 void platformSFX();
 	 void animSFX();
 	 void setPlatformMap(map *p);
 	 void setHightMap(map *p);
 	 void setBackgroundMap(map *p);
 	 void loadSample(const char *,int);
 	 void assignSample(int,rain *);
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
 	 int *getPosXP();
 	 int *getPosYP();
 	 void resetSFX(bool,int);
 	 void debug();
 };