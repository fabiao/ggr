#include "zombie.h"
#include "util.h"
#include <allegro.h>

zombie::zombie(const char *filename, int sx, int sy, BITMAP *bmp, int i, zombie *p) : sprite(filename,bmp,sx,sy,i,p)
 {
  resetObj(true);
  ti[0]=new timer_D(4);  // Move time
  ti[1]=new timer_D(10); // Rise/Unrise time
  ti[2]=new timer_D(1);  // Speed time
  ti[3]=new timer_D(1);  // Explode time
  ti[4]=new timer_D(0);
 }

zombie::~zombie()
 {
  for(int i=0;i<5;i++) delete(ti[i]);
  if(index==0)
   {
    for(int i=0;i<2;i++)            destroy_sample(sound[i]);
    for(int i=0;i<columns*rows;i++) destroy_bitmap(frames[i]);
    for(int i=0;i<columns*rows;i++) destroy_bitmap(frames_collision[i]);
   }
 }

void zombie::loadSample(const char *filename, int n)
 {
  sound[n]=load_sample(filename);
 }

void zombie::assignSample(int n,zombie *p)
 {
  sound[n]=p->sound[n];
 }


void zombie::timeSprite()
 {
  for(int i=0;i<5;i++) ti[i]->time();
 }

void zombie::animSprite()
 {
 	if(!enabled) return;
 	if(explode) 
 	 {
 	 	if(ti[3]->isOn()) act_frame++;
 	 	if(act_frame==21)
 	 	 {
 	 	  act_frame=0;
 	 	  explode=0;
 	 	  rise=0; unrise=0; move=0; dy=0;
 	 	  pos_x=random(2300);
 	 	  side=direction=random(1);
 	 	  speed=1;
 	 	  life=random(300)+300;
 	 	 }
 	 	return;
 	 }
 	if(hitted) { play_sample(sound[1],120,150,1000,0); dy=0; hitted=0; hittable=false; explode=1; move=0; rise=0; fall=0; unrise=0; act_frame=14; return; }
 	if(fall && !unrise) { act_frame=8; }
 	if(rise) 
 	 {
 	 	move=0; fall=0; unrise=0;
 	 	pos_y=plat_map->getActPlatformEnemies(pos_x,0);
 	 	if(ti[1]->isOn()) act_frame++;
 	 	if(act_frame==8) { rise=0; move=1; }
 	 }
 	if(unrise) 
 	 {
 	 	move=0; fall=0; rise=0;
 	 	if(ti[1]->isOn()) act_frame--;
 	 	if(act_frame==0)
 	 	 {
 	 	 	rise=1; unrise=0;
 	 	 	pos_x=random(2300);
 	 	 	side=direction=random(1);
 	 	 	speed=1;
 	 	 	life=random(300)+300;
 	 	 }
 	 }
 	if(move)
 	 {
 	  if(ti[2]->isOn()) pos_x+=dx;
 	  if(ti[0]->isOn()) { act_frame++; if(act_frame>13) act_frame=8; }
 	 }
 	if(side) dx=-speed; else dx=speed;
  pos_y+=dy;
  life--;
 	if(act_frame==1 && rise && inScreen() && ti[1]->isOn()) play_sample(sound[0],120,150,1000,0);
 	if(!life || plat_wall) { unrise=1; move=0; rise=0; act_frame=8; }
 	if(!rise && !move && !unrise && !hitted && !explode) { rise=1; act_frame=0; }
 }

void zombie::drawSprite(int sx,int sy)
 {
 	if(!enabled) return;
 	X=-sx+pos_x-23; Y=-sy+pos_y-12;
 	if(act_frame>6 && act_frame<14) can_hit=true; else can_hit=false;
  if(act_frame>3 && act_frame<14) hittable=true; else hittable=false;
 	if(inScreen())
 	 {
    if(side) draw_sprite_h_flip(screen,frames[act_frame],X,Y);
    else     draw_sprite       (screen,frames[act_frame],X,Y);
   }
 }

void zombie::platformSprite()
 {
 	if(!enabled) return;
 	if(hitted || explode) return;
 	plat_wall=0;
 	if(!rise && !unrise && !hitted && !explode)
 	 {
 	  if(pos_y>plat_y) if(pos_y-plat_y<=8) pos_y=plat_y; 
 	  if(pos_y<plat_y) if(plat_y-pos_y<=8) pos_y=plat_y; 
 	  if(pos_y<plat_y) { fall=1; dy++; if(dy>6) dy=6; dx=0; } else { fall=0; dy=0; }
 	 }
 	plat_y=plat_map->getActPlatformEnemies(pos_x,pos_y);
 	if(!unrise) plat_wall=plat_map->getActPlatformEnemies(pos_x,pos_y,2,direction);
 	plat_stair=0;//plat_map->getActStairEnemies(1);
 }

BITMAP *zombie::getActFrameColP() { return frames_collision[act_frame]; }

bool zombie::inScreen()
 {
 	if(X>=-32 && X<=384) return true;
 	else return false;
 }

int zombie::getPlatYPos() { return plat_y; }

int *zombie::getPosXP() { return &pos_x; }

int *zombie::getPosYP() { return &pos_y; }

int zombie::getScore() { return 50; }

void zombie::setPlatformMap(map *p) { plat_map=p; }

void zombie::setHightMap(map *p) { hight_map=p; }

void zombie::setBackgroundMap(map *p) { back_map=p; }

void zombie::setHitted(bool b) { hitted=b; }

bool zombie::canHit() { return can_hit; }

bool zombie::isHittable() { return hittable; }

void zombie::resetObj(bool enb)
 {
  enabled=enb;
  pos_x=start_x; pos_y=start_y; scroll_x=0; scroll_y=0; jump_y=0;
  dx=0; dy=0; plat_y=start_y;
  act_frame=0;
  life=random(300)+300; speed=1; pos_x=random(2300);
  move=0; fall=0; rise=0; unrise=0; hitted=0; explode=0;
  side=0; direction=0;
  plat_wall=0; 	
 }

void zombie::debug()
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
