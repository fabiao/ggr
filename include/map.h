#pragma once

#include "mobile.h"

struct BITMAP;

class map
 {
  private:
   int scroll_stop_x,scroll_stop_y;
   int num_col=0,num_row=0;
   int tile_h=0,tile_w=0;
   int num_pages_x=0,num_pages_y=0;
   int tilemax_x=0,tilemax_y=0;
   int max_bound_y=0;
   int *ctrl_x,*ctrl_y;
   int scroll_x,scroll_y,scroll_dx=0,scroll_dy=0;
   int tilepos_x=0,tilepos_y=0;
   int speed_x=0,speed_y=0;
   bool main_scroll,hscroll_on,vscroll_on;
   BITMAP *tile[32*32];
   BITMAP *out;
   mobile **mobilep;
   int data[300][300];
   int platform[300][300];
   int platformdata[100][32];
   int stairs[300][300];
   int wall[300][300];
   int walldata[50][2];
   int n_plat;

   void setOutBitmap(BITMAP *);

  public:
   map(const char *,const char *,BITMAP *,bool mainscroll=false,const char *plat_filename="",const char *dat_plat_filename="",const char *stairs_filename="",const char *wall_filename="",const char *dat_wall_filename="",bool loadall=false);
   ~map();
   void drawMap();
   void scrollMap();
   void loadMap(const char *,const char *);
   void loadPlatform(const char *,const char *);
   void loadStairs(const char *);
   void loadWall(const char *,const char *);
   void setMobileP(mobile **p,int);
   void setHScroll(bool,int ss=0);
   void setVScroll(bool,int ss=0);
   void setSpeedX(int);
   void setSpeedY(int);
   void setCtrlXP(int *p);
   void setCtrlYP(int *p);
   void setScrollX(int);
   void setScrollY(int);
   int getTileW();
   int getTileH();
   int getNumCol();
   int getNumRow();
   int getTotCol();
   int getTotRow();
   int getScrollX();
   int getActTileX();
   int getTileOffsetX();
   int getScrollY();
   int getActTileY();
   int getTileOffsetY();
   int getActPlatform(int,int);
   int getActPlatLayer(int,int,int,bool);
   int getActPlatLayerValue(int,int,int,int);
   int getActPlatformMobile(int,int);
   int getActWall(bool,int,int);
   int getActWallMobile(bool,int,int);
   int getActStair(int,int);
   int getActPlatformEnemies(int,int,int type=0,bool side=0);
   void debug();
 };
