#pragma once

#include "timer_D.h"

struct BITMAP;

class mobile
 {
  private:
   int bonus_seq,start_x,start_y,pos_x,pos_y,scroll_x,scroll_y,jump_y,X,Y,_i;
   int *glob_bonus_seq;
   int plat_y,plat_stair,plat_wall;
   int dis_x,dis_y; // Distanza di apparizione (solo per magic box)
   int dx,dy,max_y,min_y;
   int *ctrl_x,*ctrl_y;
   int bak_frame,act_frame,start_frame,end_frame;
   int energy,life,speed,type;
   int *difficulty;
   bool side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool can_hit,hittable,fground;
   bool dead,active,hide,move,down,fire1,fire2,fall,rise,unrise,hitted,explode;
   timer_D *ti[5];
   BITMAP *frame[100];
   BITMAP *frame_col[100];
   BITMAP *out;
   int mobiledata[100][6+48]; // 0 dis. muro da sinistra
                              // 1 dist. muro da destra
                              // 2 altezza muro sin.
                              // 3 altezza muro des.
                              // 4 pixel per hit orizzontale 
                              // 5 pixel per hit verticale
                              // 6 altezza piattaforma (o altre 47 altezze per altezza variabile (TODO) ???)
   void loadSpriteFrames(const char *);
   void loadMobile(const char *dat_mobile_filename);
   void assignSpriteFrame(mobile *);
   void setOutBitmap(BITMAP *);

  public:
   mobile(const char *,const char *,int,int,int,int,int,BITMAP *,int i=0,mobile *p=NULL);
   ~mobile();
   void setStartX(int);
   void setStartY(int);
   void setMaxY(int);
   void setMinY(int);
   void setDisX(int);
   void setDisY(int); 
   void setBonusSeqP(int *);
   void setDifficultyP(int *);
   void setFGround(bool);  
   bool isActive();
   void drawSprite(int,int);
   void timeSprite();
   void animSprite();
   void loadSample(const char *,int);
   void assignSample(int,mobile *);
   BITMAP *getActFrameColP();
   bool inScreen();
   int getBonusSeq(int,bool,bool);
   int getPlatYPos();
   int getMobileH();
   int getWallLeft();
   int getWallHLeft();
   int getWallRight();
   int getWallHRight();
   int getX();
   int getY();
   int getEnergy();
   int getHHit();
   int getVHit();
   bool getFGround();
   int *getPosXP();
   int *getPosYP();
   void setCtrlXP(int *);
   void setCtrlYP(int *);
   void setStartFrame(int);
   void setEndFrame(int);
   void setType(int);
   void setHitted(bool);
   bool canHit();
   bool isHittable();
   void resetObj(bool);
   void debug();
 };