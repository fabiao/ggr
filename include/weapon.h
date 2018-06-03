#pragma once

#include "timer_D.h"
#include "map.h"

struct BITMAP;
struct SAMPLE;

class weapon
 {
 	private:
 	 enum { _COL=25, _ROW=5, _XPIX=46, _YPIX=46 };
 	 int index,plat_layer;
   int actWeapon,frame_offset,min_frame,max_frame,grframe_min,grframe_max,max_life,grmax_life,max_power,status;
 	 int pos_x,pos_y,scroll_x,scroll_y,jump_y,X,Y,hit_x,hit_y,_i;
 	 int plat_y,plat_stair,plat_wall,power;
 	 int dx,dy;
 	 int act_frame,hard_frame,soft_frame;
 	 int life,speed,speed_d,speed_ud,movedir,gravity,multi;
 	 int *player_x,*player_y;
 	 bool animated,powerup,no_zeropower,canhit_ground;
 	 bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
 	 bool can_hit;
 	 bool stop,move,jump_up,jump_down,down,climb,fire,fire2,fall,turn,rise,unrise,hard,soft;
 	 timer_D *ti[5];
 	 SAMPLE *sound[4];
 	 BITMAP *frame[_COL*_ROW];
 	 BITMAP *frame_col[2][_COL*_ROW];
 	 BITMAP *out;
 	 map *plat_map;
 	 map *hight_map;
 	 map *back_map;

 	 void loadSpriteFrames(const char *);
 	 void assignSpriteFrame(weapon *p);
 	 void setOutBitmap(BITMAP *);
 	
 	public:
 	 weapon(const char *,BITMAP *,int i=0,weapon *p=NULL);
 	 ~weapon();
 	 void drawSprite(int,int);
 	 void timeSprite();
 	 void platformSprite();
 	 void animSprite();
 	 void setPlatLayer(int);
 	 void setPlatformMap(map *p);
 	 void setHightMap(map *p);
 	 void setBackgroundMap(map *p);
 	 void loadSample(const char *,int);
 	 void assignSample(int,weapon *);
 	 BITMAP *getActFrameColP();
 	 bool inScreen();
 	 int getPlatLayer();
 	 int getActWeapon();
 	 int setActWeapon(int,bool);
 	 int minIndex(int,bool);
 	 void setIndex(int);
 	 void setPlayerXP(int *);
 	 void setPlayerYP(int *);
 	 int getPlatYPos();
 	 int getX();
 	 int getY();
 	 int getMoveDir();
 	 int *getPosXP();
 	 int *getPosYP();
 	 void shoot(int,int,bool,int,int,bool,bool,bool,bool);
 	 void hit(int fl=1);
 	 void hitSoft();
 	 void hitHard();
 	 void hitGround(int);
 	 bool isFired();
 	 int getMulti();
 	 bool canHit();
 	 void debug();
 };