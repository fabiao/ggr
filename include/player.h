#pragma once

#include "sprite.h"
#include "timer_D.h"
#include "map.h"
#include "bullet.h"
#include "bonus.h"
#include "weapon.h"
#include "magic.h"
#include "osd.h"

struct BITMAP;
struct SAMPLE;

class player : public sprite
 {
  private:
   enum { N_WE=52 };
   int KEYLEFT,KEYRIGHT,KEYUP,KEYDOWN,KEYJUMP,KEYSHOOT; // Move player keyboard config
   int plat_layer;
   int max_we;
   int pos_x,pos_y,glob_x,glob_y,scroll_x,scroll_y,jump_y,restart_x,restart_y;
   int scroll_center_x,scroll_center_y,max_x,max_y;
   int *stage,*lives,*score,*ckpoint,*interlude,*epilogue,n_stage;
   int armo_x[6],armo_y[6];
   int shild_x[2],shild_y[2];
   int plat_y,plat_stair,plat_wall;
   int dx,dy;
   int dress,armour_count,shild_count,gold_frame,bigfrm,gauge_frame;
   bonus *bshild;
   int gauge;
   bool magicpw;
   bool canFire,side,direction; // posizione speculare e direzione di moto 0 = destra, 1 = sinistra
   bool stop,move,gold,magicfire,magicshoot,jump_up,jump_down,jump_hit_up,jump_hit_down,down,climb,fire1,fire2,fire_down,fire_up,fall,turn,dead,restart,ready_go;
   bool hittable,hitted,armour_down,armour_side,shild_down,shild_side;
   bool shild,powerup;
   bool key_taked;
   BITMAP **frames_col[2]; // Mirror collision frames for player
   timer_D *ti[8];
   weapon *weap[N_WE];
   magic  *magi;
   SAMPLE *sound[15];
   map *plat_map;
   map *hight_map;
   map *back_map;
   osd *_osd;

   void addGlobY(int);
   void addGlobX(int);
   void shootWeapon();
   void shootMagic();
   void resetArmour();
   void resetShild();
   void moveArmour();
   void moveShild();
 	
  public:
   player(const char *,int,int,BITMAP *,int i=0, player *p=NULL);
   ~player();
   void drawSprite();
   void drawShild(bool);
   void drawCloak();
   void drawGauge();
   void timeSprite();
   void platformSprite();
   void moveSprite();
   void animSprite();
   void setOSD(osd *);
   void setPlatformMap(map *p);
   void setHightMap(map *p);
   void setBackgroundMap(map *p);
   void takeBonus(int,int extra=0);
   void loadSample(const char *,int);
   void resetPlayer(int,int,bool first=false);
   BITMAP *getActFrameColP(bool sh=false);
   int getActPlatLayer();
   bool *getMagicpwP();
   int *getMagicGaugeP();
   weapon *getWeapon(int);
   magic *getMagic();
   void setScrollCenterX(int);
   void setScrollCenterY(int);
   void setNStage(int);
   void setStageP(int *);
   void setInterludeP(int *);
   void setEpilogueP(int *);
   void setCkPointP(int *);
   void setLivesP(int *);
   void setScoreP(int *);
   void setShildP(bonus *);
   void setShildHit(bool);
   void setShild(bool);
   void setDress(int);
   void setSide(int);
   void setKeyboardLayout(int,int,int,int,int,int);
   int getKeyShoot();
   int getKeyJump();
   bool getReadyGo();
   bool getShild();
   bool getPowerUp();
   bool getKeyTaked();
   int getDress();
   int getPlatYPos();
   int getActWeapon();
   int getPosX();
   int getPosY();
   int getNWeapon();
   int getNMagic();
   int getGlobX();
   int getGlobY();
   int *getScrollXP();
   int *getScrollYP();
   int *getGlobXP();
   int *getGlobYP();
   BITMAP *getFrame(int);
   void setHitted(bool);
   bool isHittable();
   bool isGold();
   bool isMagicFire();
   void calcMax();
   void debug();
 };