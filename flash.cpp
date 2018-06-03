#include "flash.h"
#include <allegro.h>

flash::flash(int sx, int sy, BITMAP *out, int i, flash *p)
 {
 	_i=i;
 	setOutBitmap(out);
 	start_x=sx; start_y=sy;
 	resetSFX(true);
 	ti[0]=new timer_D(3); // Anim time
 	ti[1]=new timer_D(200); // Anim pause time
 	ti[2]=new timer_D(0);
 	ti[3]=new timer_D(0);
 	ti[4]=new timer_D(0);
 }

flash::~flash()
 {
 	for(int i=0;i<5;i++) delete(ti[i]);
 	if(_i==0)
 	 {
    for(int i=0;i<1;i++)    destroy_sample(sound[i]);
 	  //for(int i=0;i<25*3;i++) destroy_bitmap(frame[i]);
 	  //for(int i=0;i<25*3;i++) destroy_bitmap(frame_col[i]);
 	 }
 }

void flash::loadSample(const char *filename, int n)
 {
 	sound[n]=load_sample(filename);
 }

void flash::setOutBitmap(BITMAP *bmp) { out=bmp; }

void flash::timeSFX()
 {
 	for(int i=0;i<5;i++) ti[i]->time();
 }

void flash::animSFX()
 {
 	if(!active) return;
 	if((*ctrl_x<act_x || *ctrl_y<act_y) && !ison) return;
 	if(stop) { if(ti[1]->isOn()) { stop=0; ison=1; count=0; play_sample(sound[0],120,150,1000,0); } }
 	if(ison) 
 	 {
 	 	if(count<3) 
 	 	 {
 	 	  r=g=b=255;
 	 	  if(ti[0]->isOn())
 	 	   {
 	 	 	  count++;
 	 	 	  r=g=b=0;
 	 	   }
 	 	 }
 	 	if(count>=3)
 	 	 {
 	 	  count++;
			r=g=b=250-(count-4)*10;
 	 	 }
 	 	if(count==25) { stop=1; ison=0; ti[1]->reset(); r=g=b=0; }
 	 	act_color=makecol32(r,g,b);
 	 }
 }

void flash::drawSFX(int sx,int sy)
 {
 	if(!active) return;
 	//X=-sx+pos_x-23; Y=-sy+pos_y-12;
 	//if(inScreen())
 	 {
 	 	rectfill(out,0,70,384,224,act_color);
   }
 }

void flash::platformSFX()
 {
 	if(!active) return;
 	/*if(hitted || explode) return;
 	plat_wall=0;
 	if(!jump_down && !jump_up && !rise && !unrise && !hitted && !explode)
 	 {
 	  if(pos_y>plat_y) if(pos_y-plat_y<=8) pos_y=plat_y; 
 	  if(pos_y<plat_y) if(plat_y-pos_y<=8) pos_y=plat_y; 
 	  if(pos_y<plat_y) { fall=1; dy++; dx=0; } else { fall=0; dy=0; }
 	 }
 	plat_y=plat_map->getActPlatformEnemies(pos_x,pos_y);
 	if(!unrise) plat_wall=plat_map->getActPlatformEnemies(pos_x,pos_y,2,direction);
 	plat_stair=0;//plat_map->getActStairEnemies(1);*/
 }

BITMAP *flash::getActFrameColP() { return frame_col[act_frame]; }

bool flash::inScreen()
 {
  if(X>=-32 && X<=384) return true;
  else return false;
 }

bool flash::isOn() { return ison; }

int flash::getPlatYPos() { return plat_y; }

int flash::getX() { return X; }

int flash::getY() { return Y; }

void flash::setStartX(int sx) { start_x=sx; }

void flash::setStartY(int sy) { start_y=sy; }

void flash::setCtrlXP(int *p) { ctrl_x=p; }

void flash::setCtrlYP(int *p) { ctrl_y=p; }

int *flash::getPosXP() { return &pos_x; }

int *flash::getPosYP() { return &pos_y; }

void flash::setPlatformMap(map *p) { plat_map=p; }

void flash::setHightMap(map *p) { hight_map=p; }

void flash::setBackgroundMap(map *p) { back_map=p; }

void flash::resetSFX(bool act)
 {
 	active=act;
 	act_x=pos_x=start_x; act_y=pos_y=start_y; scroll_x=0; scroll_y=0; jump_y=0;
 	dx=0; dy=0; plat_y=start_y;
 	ison=0;
 	stop=1;
 	plat_wall=0;
 	count=r=g=b=0;
 	act_frame=0; act_color=makecol32(r,g,b); 	
 }

void flash::debug()
 {
 	putpixel(out,pos_x,pos_y-30+58,makecol32(255,0,0));
  putpixel(out,pos_x,pos_y-30+59,makecol32(255,0,0));
  putpixel(out,pos_x,pos_y-30+60,makecol32(255,0,0));
  putpixel(out,pos_x,pos_y-30+61,makecol32(255,0,0));
  putpixel(out,pos_x,pos_y-30+62,makecol32(255,0,0));
  putpixel(out,pos_x-2,pos_y-30+60,makecol32(255,0,0));
  putpixel(out,pos_x+2,pos_y-30+60,makecol32(255,0,0));
  putpixel(out,pos_x-1,pos_y-30+61,makecol32(255,0,0));
  putpixel(out,pos_x+1,pos_y-30+61,makecol32(255,0,0));
 }
