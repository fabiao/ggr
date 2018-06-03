#pragma once

#include "timer_D.h"
#include "map.h"

struct BITMAP;
struct SAMPLE;

class snow
 {
 	private:
 	 int start_x,start_y,pos_x,pos_y,scroll_x,scroll_y,act_x,act_y,jump_y,X,Y,_i;
 	 int plat_y,plat_stair,plat_wall;
 	 int *ctrl_x,*ctrl_y;
 	 int dx,dy,alpha;
 	 int r,g,b,count;
 	 int *RX,*RY,*RS,num_drops;
 	 bool active,stop,ison,type,snowing;
 	 int max_drops;
 	 int act_frame,act_color;
 	 timer_D *ti[5];
 	 SAMPLE *sound[4];
 	 //BITMAP *frame[100];
 	 //BITMAP *frame_col[100];
 	 BITMAP *out,*snow_bmp;
 	 int TRA,COL1;
 	 unsigned char snow_map[640][50];
 	 map *plat_map;
 	 map *hight_map;
 	 map *back_map;

 	 void setOutBitmap(BITMAP *);
 	
 	public:
 	 snow(int,int,BITMAP *,int i=0,snow *p=NULL);
 	 ~snow();
 	 void drawSFX(int,int);
 	 void timeSFX();
 	 void platformSFX();
 	 void animSFX();
 	 void setPlatformMap(map *p);
 	 void setHightMap(map *p);
 	 void setBackgroundMap(map *p);
 	 void loadSample(const char *,int);
 	 void assignSample(int,snow *);
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