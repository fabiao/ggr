#pragma once

#include "timer_D.h"
#include "map.h"

struct BITMAP;
struct SAMPLE;

class bullet
 {
  private:
   int pos_x,pos_y,scroll_x,scroll_y,jump_y,X,Y,hit_x,hit_y,_i;
   int plat_y,plat_stair,plat_wall;
   int dx,dy;
   int start_frame,end_frame,typ;
   int act_frame,hit_frame;
   int life,speed;
   int angle,dist; // Used for rotating bullets
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool can_hit;
   bool stop,move,jump_up,jump_down,down,climb,fire,fall,turn,rise,unrise;
   timer_D *ti[5];
   SAMPLE *sound[4];
   BITMAP *frame[75];
   BITMAP *frame_col[75];
   BITMAP *out;
   map *plat_map;
   map *hight_map;
   map *back_map;

   void setOutBitmap(BITMAP *);

  public:
   bullet(const char *,BITMAP *,int i=0,int sta_fr=50,int end_fr=53,int ty=0);
   ~bullet();
   void drawSprite(int,int);
   void timeSprite();
   void platformSprite();
   void animSprite();
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void loadSample(const char *,int);
   void assignSample(int,bullet *);
   BITMAP *getActFrameColP();
   void setAngle(int);
   void setFrameP(int,BITMAP *);
   void setFrameColP(int,BITMAP *);
   bool inScreen();
   int getPlatYPos();
   int getX();
   int getY();
   int *getPosXP();
   int *getPosYP();
   void shoot(int,int,int,int,bool);
   void hit();
   bool isFired();
   bool canHit();
   void resetObj();
   void debug();
 };