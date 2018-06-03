#pragma once

#include "timer_D.h"

struct BITMAP;

class osd
 {
 	private:
 	 enum { _COL=33, _ROW=3, _XPIX=32, _YPIX=30 };
 	 int X,Y,_i;
 	 int *lives,*score,*gauge,*min,*sec;
 	 int weapon_frame;
 	 int alpha;
 	 bool powerup,*magicpw;
 	 timer_D *ti[5];
 	 BITMAP *frame[_COL*_ROW];
 	 BITMAP *out;

 	 void loadSpriteFrames(const char *);
 	 void assignSpriteFrame(osd *);
 	 void setOutBitmap(BITMAP *);
 	 void energyBar();
 	
 	public:
 	 osd(const char *,int,int,BITMAP *,int i=0,osd *p=NULL);
 	 ~osd();
 	 void drawOSD(int,int);
 	 void timeOSD();
 	 void animOSD();
 	 bool inScreen();
 	 void setActWeapon(int,bool);
 	 void setMagicpwP(bool *);
 	 void setMagicGaugeP(int *);
 	 void setLivesP(int *);
 	 void setScoreP(int *);
 	 void setMinSecP(int *,int *);
 	 void debug();
 };