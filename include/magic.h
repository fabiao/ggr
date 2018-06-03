#pragma once

#include "timer_D.h"
#include "map.h"

struct BITMAP;
struct SAMPLE;

class magic
 {
  private:
   enum { _COL=24, _ROW=4, _XPIX=48, _YPIX=48, NUM_SPRITE=9, OFF=0, DOWN=1, HORIZ=2, LOAD=3, ON=4, DIAG_UP=5, DIAG_DOWN=6 };
   int index,plat_layer;
   int actWeapon,frame_offset,max_life,max_power;
   int scroll_x,scroll_y,jump_y,hitsoft_x,hitsoft_y,hithard_x,hithard_y,_i;
   int plat_y,plat_stair,plat_wall,power;
   int dx,dy;
   int hard_frame,soft_frame;
   int life,speedx,speedy,movedir,tick;
   int *player_x,*player_y;
   bool animated,two;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool can_hit;
   bool stop,move,jump_up,jump_down,down,climb,fire,fire2,fall,turn,rise,unrise,hard,soft;
   timer_D *ti[5];
   SAMPLE *sound[4];
   BITMAP *frame[_COL*_ROW];
   BITMAP *frame_col[2][_COL*_ROW];
   BITMAP *out;
   int X[NUM_SPRITE],Y[NUM_SPRITE],POSX[NUM_SPRITE],POSY[NUM_SPRITE],STATO[NUM_SPRITE];
   int ACT_FRAME[NUM_SPRITE],MIN_FRAME[NUM_SPRITE],MAX_FRAME[NUM_SPRITE];
   map *plat_map;
   map *hight_map;
   map *back_map;

   void loadSpriteFrames(const char *);
   void assignSpriteFrame(magic *p);
   void setOutBitmap(BITMAP *);
 	
  public:
   magic(const char *,BITMAP *,int i=0,magic *p=NULL);
   ~magic();
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setPlatLayer(int);
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,magic *);
   BITMAP *getActFrameColP(int);
   bool inScreen();
   int getPlatLayer();
   int getActWeapon();
   int setActWeapon(int);
   int getNSprites();
   void setIndex(int);
   void setPlayerXP(int *);
   void setPlayerYP(int *);
   int getTick();
   int getPlatYPos();
   int getX(int);
   int getY(int);
   int getMoveDir();
   int *getPosXP();
   int *getPosYP();
   void shoot(int,int,bool,int,int,bool,bool,bool);
   void hit(int fl=1);
   void hitSoft(int);
   void hitHard(int);
   bool isFired();
   bool isTwo();
   bool canHit();
   void debug();
 };