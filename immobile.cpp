#include "immobile.h"
#include "util.h"
#include <allegro.h>

immobile::immobile(const char *filename, int sx, int sy, int my, int co, BITMAP *bmp, int fr, int i, immobile *p) : sprite(filename,bmp,sx,sy,i,p)
 {
  maxy=my; afr=fr; coun=co;
  resetObj(true);
  ti[0]=new timer_D(16); // Restart time
  ti[1]=new timer_D(2);  // Shake time
  ti[2]=new timer_D(0);
  ti[3]=new timer_D(0);
  ti[4]=new timer_D(0);
 }

immobile::~immobile()
 {
  for(int i=0;i<5;i++) delete(ti[i]);
  if(index==0)
   {
    for(int i=0;i<1;i++)            destroy_sample(sound[i]);
 	for(int i=0;i<columns*rows;i++) destroy_bitmap(frames[i]);
 	for(int i=0;i<columns*rows;i++) destroy_bitmap(frames_collision[i]);
   }
 }

void immobile::loadSample(const char *filename, int n)
 {
  sound[n]=load_sample(filename);
 }

void immobile::assignSample(int n,immobile *p)
 {
  sound[n]=p->sound[n];
 }

void immobile::timeSprite()
 {
  for(int i=0;i<5;i++) ti[i]->time();
 }

void immobile::animSprite()
 {
  if(!enabled) return;
  if(action==_NONE) return;
 }

void immobile::drawSprite(int sx,int sy)
 {
  if(!enabled) return;
  X=-sx+pos_x; Y=-sy+pos_y;
     //-23;        //-12;
  if(inScreen())
   {
    if(side) draw_sprite_h_flip(screen,frames[act_frame],X,Y);
    else     draw_sprite       (screen,frames[act_frame],X,Y);
   }
 }

void immobile::platformSprite()
 {
  if(!enabled) return;
  if(!jump_down && !jump_up && !climb)
   {
 	if(pos_y>plat_y) if(pos_y-plat_y<=8) pos_y=plat_y; 
 	if(pos_y<plat_y) if(plat_y-pos_y<=8) pos_y=plat_y; 
 	if(pos_y<plat_y) { fall=1; dy++; dx=0; } else { fall=0; dy=0; }
   }
  //plat_y=plat_map->getActPlatform();
  plat_wall=0;//plat_map->getActWall(direction);
  plat_stair=0;//plat_map->getActStair();
 }
 
BITMAP *immobile::getActFrameColP() { return frames_collision[act_frame]; }

bool immobile::inScreen()
 {
  if(X>=-64 && X<=384) return true;
  else return false;
 }

int immobile::getPlatYPos() { return plat_y; }

int *immobile::getPosXP() { return &pos_x; }

int *immobile::getPosYP() { return &pos_y; }

void immobile::setPlatformMap(map *p) { plat_map=p; }

void immobile::setHightMap(map *p) { hight_map=p; }

void immobile::setBackgroundMap(map *p) { back_map=p; }

void immobile::setStartXYFrame(int sx, int sy, int fr) { start_x=sx; start_y=sy; afr = fr; }

void immobile::setMaxY(int my) { maxy=my; }

void immobile::setCount(int co) { coun=co; }

void immobile::setActualFrame(int fr) { afr = fr; }

void immobile::resetObj(bool enb)
 {
  enabled=enb;
  pos_x=start_x; pos_y=start_y; scroll_x=0; scroll_y=0;
  min_y=start_y;
  dx=0; dy=0; plat_y=start_y; max_y=maxy;
  act_frame=afr;
  count=coun;
  action = _NONE;
  side=0; direction=0;
 }

void immobile::debug()
 {
  putpixel(screen,pos_x,pos_y-30+58,makecol32(255,0,0));
  putpixel(screen,pos_x,pos_y-30+59,makecol32(255,0,0));
  putpixel(screen,pos_x,pos_y-30+60,makecol32(255,0,0));
  putpixel(screen,pos_x,pos_y-30+61,makecol32(255,0,0));
  putpixel(screen,pos_x,pos_y-30+62,makecol32(255,0,0));
  putpixel(screen,pos_x-2,pos_y-30+60,makecol32(255,0,0));
  putpixel(screen,pos_x+2,pos_y-30+60,makecol32(255,0,0));
  putpixel(screen,pos_x-1,pos_y-30+61,makecol32(255,0,0));
  putpixel(screen,pos_x+1,pos_y-30+61,makecol32(255,0,0));
 }
