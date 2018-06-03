#pragma once

#include "map.h"
#include "timer_D.h"

struct SAMPLE;
struct BITMAP;

class bonus
 {
 	private:
 	 enum { _COL=25, _ROW=3, _XPIX=46, _YPIX=46 };
 	 int *vasex,*vasey,vase_px,vase_py;
 	 int open,taked,takeble,type,start_x,start_y,afr,pos_x,pos_y,scroll_x,scroll_y,X,Y,_i;
 	 int plat_y,plat_stair,plat_wall;
 	 int dx,dy;
 	 int act_frame,min_frame,max_frame;
 	 bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
 	 bool active,stop,move,jump,fire,fall,attached;
 	 timer_D *ti[5];
 	 SAMPLE *sound[4];
 	 BITMAP *frame[_COL*_ROW];
 	 BITMAP *frame_col[_COL*_ROW];
 	 BITMAP *out;
 	 map *plat_map;
 	 map *hight_map;
 	 map *back_map;
 	 bonus *invase;
 	 
 	 void loadSpriteFrames(const char *);
 	 void assignSpriteFrame(bonus *);
 	 void setOutBitmap(BITMAP *);
 	
 	public:
 	 bonus(const char *,int,int,BITMAP *,int fr=0,int i=0,bonus *p=NULL);
 	 ~bonus();
 	 void drawSprite(int,int);
 	 void timeSprite();
 	 void platformSprite();
 	 void animSprite();
 	 void setStartX(int);
 	 void setStartY(int);
 	 void setVaseX(int *);
 	 void setVaseY(int *);
     void setVasepx(int);
     void setVasepy(int);
 	 void setTaked(bool);
 	 void setAttached(bool);
 	 void setInvaseP(bonus *);
 	 bool isTaked();
 	 bool isTakeble();
 	 bool isActive();
 	 void setPlatformMap(map *p);
 	 void setHightMap(map *p);
 	 void setBackgroundMap(map *p);
 	 void loadSample(const char *,int);
 	 void assignSample(int,bonus *);
 	 BITMAP *getActFrameColP();
 	 bool inScreen();
 	 int getPlatYPos();
 	 int getX();
 	 int getY();
 	 int *getPosXP();
 	 int *getPosYP();
 	 int getExtra();
 	 int getType();
 	 void resetObj(bool,int typ=0);
 	 void debug();
 };