#include "clam.h"
#include "util.h"
#include <allegro.h>

clam::clam(const char *filename, int sx, int sy, BITMAP *bmp, int i, clam *p) : sprite(filename,bmp,sx,sy,i,p)
 {
  // Bullet (assegno i frame ai proiettili prendendoli dalla memoria gi� allocata)
  // Per adesso nessun "sound" � assegnato ai proiettili
  //BU[0]->loadSample("data/sound/fx/hard.wav",0);  	
  for(int i=0;i<N_BU;i++)
   {
   	BU[i]=new bullet("",bmp,1,50,52,1);
    //BU[i]->assignSample(0,BU[0]);
  	for(int j=0;j<rows*columns;j++)
     {
      BU[i]->setFrameP(j,frames[j]);
      BU[i]->setFrameColP(j,frames_collision[j]);
     }
   }
  resetObj(true);
  ti[0]=new timer_D(10);  // Anim time
  ti[1]=new timer_D(2);   // Explode time
  ti[2]=new timer_D(random(100)+60);  // Fire time 1
  ti[3]=new timer_D(random(200)+100); // Fire time 2
  ti[4]=new timer_D(0);
 }

clam::~clam()
 {
  for(int i=0;i<N_BU;i++) delete(BU[i]);
  for(int i=0;i<5;i++) delete(ti[i]);
  if(index==0)
   {
    for(int i=0;i<2;i++)            destroy_sample(sound[i]);
 	for(int i=0;i<columns*rows;i++) destroy_bitmap(frames[i]);
 	for(int i=0;i<columns*rows;i++) destroy_bitmap(frames_collision[i]);
   }
 }

void clam::loadSample(const char *filename, int n)
 {
  sound[n]=load_sample(filename);
 }

void clam::assignSample(int n,clam *p)
 {
  sound[n]=p->sound[n];
 }

void clam::timeSprite()
 {
  for(int i=0;i<5;i++) ti[i]->time();
 }

void clam::shootBullet()
 {
 	int n=-1;
 	
 	//play_sample(sound[0],120,150,1000,0);
 	for(int i=0;i<N_BU;i++) if(!BU[i]->isFired()) { n=i; break; }
 	if(n!=-1)
 	 {
 	 	if(fire)
 	 	 {
  	  BU[n]->shoot(pos_x,pos_y,*ctrl_x,*ctrl_y+7,side);
  	 }
   }
 }

void clam::animSprite()
 {
 	if(!enabled) return;
 	if(dead) return;
 	if(explode) 
 	 {
 	 	if(ti[1]->isOn()) act_frame++;
 	 	if(act_frame==11)
 	 	 {
 	 	  act_frame=0;
 	 	  dead=1;
 	 	  hitted=0;
 	 	  explode=0;
 	 	  move=0;
 	 	  open=0;
 	 	  fire=0;
 	 	 }
 	 	return;
 	 }
 	if(ti[2]->isOn() || ti[3]->isOn()) { fire=1; move=0; open=1; ti[0]->reset(); act_frame=25; }
 	if(ti[3]->isOn()) ti[2]->reset();
 	if(move) { if(ti[0]->isOn()) act_frame++; if(act_frame>4) act_frame=1; }
 	if(open) { if(ti[0]->isOn()) act_frame++; if(act_frame>26) { move=1; open=0; act_frame=2; } }
 	if(hitted) { play_sample(sound[0],120,150,1000,0); hitted=0; /*act_frame=19; stop=1;*/ energy--; if(energy==0) { open=0; explode=1; move=0; act_frame=5; /*stop=0;*/ play_sample(sound[1],120,150,1000,0); } else explode=0; ti[2]->reset(); return; }
 	if(fire) { shootBullet(); fire=0; }
 }

void clam::drawSprite(int sx,int sy)
 {
 	if(!enabled) return;
  //pivotsprite(rend,car,rend_x,rend_y,piv_cx,piv_cy,itofix(ang1));
  X=-sx+pos_x-23; Y=-sy+pos_y-12;
  if((act_frame>0 && act_frame<5) || (act_frame>=25 && act_frame<27)) can_hit=true; else can_hit=false;
  if(act_frame<5 || (act_frame>=25 && act_frame<27)) hittable=true; else hittable=false;
  if(inScreen())
   {
    if(side) draw_sprite_h_flip(screen,frames[act_frame],X,Y);
    else     draw_sprite       (screen,frames[act_frame],X,Y);
   }
  // Bullet
  for(int i=0;i<N_BU;i++)
   {
   	BU[i]->drawSprite(sx,sy);
    BU[i]->timeSprite();
 	  BU[i]->animSprite();
 	  //BU[i]->platformSprite();
    //BU[i]->drawSprite(plat_map->getScrollX());
   }
 }

void clam::platformSprite()
 {
 	if(!enabled) return;
 	/*if(!jump_down && !jump_up && !climb)
 	{
 	 if(pos_y>plat_y) if(pos_y-plat_y<=8) pos_y=plat_y; 
 	 if(pos_y<plat_y) if(plat_y-pos_y<=8) pos_y=plat_y; 
 	 if(pos_y<plat_y) { fall=1; dy++; dx=0; } else { fall=0; dy=0; }
 	}
 	//plat_y=plat_map->getActPlatform();
 	plat_wall=0;//plat_map->getActWall(direction);
 	plat_stair=0;//plat_map->getActStair();*/
 }

bullet *clam::getBullet(int n) { return BU[n]; }

BITMAP *clam::getActFrameColP() { return frames_collision[act_frame]; }

bool clam::inScreen()
 {
  if(X>=-62 && X<=384) return true;
  else return false;
 }

int clam::getPlatYPos() { return plat_y; }

int clam::getScore() { if(energy==1) return 300; else return 0; }

int clam::getNBullet() { return N_BU; }

void clam::setCtrlXP(int *p) { ctrl_x=p; }

void clam::setCtrlYP(int *p) { ctrl_y=p; }

void clam::setSide(bool s) { side=s; }

int *clam::getPosXP() { return &pos_x; }

int *clam::getPosYP() { return &pos_y; }

void clam::setPlatformMap(map *p) { plat_map=p; }

void clam::setHightMap(map *p) { hight_map=p; }

void clam::setBackgroundMap(map *p) { back_map=p; }

void clam::setHitted(bool b) { hitted=b; }

bool clam::canHit() { return can_hit; }

bool clam::isHittable() { return hittable; }

void clam::resetObj(bool enb)
 {
  enabled=enb;
  pos_x=start_x; pos_y=start_y; scroll_x=0; scroll_y=0; jump_y=0;
  energy=6;
  dx=0; dy=0; plat_y=start_y;
  act_frame=1;
  stop=0; move=1; fire=0; open=0; hitted=0; dead=0; explode=0;
  direction=0;
  for(int i=0;i<N_BU;i++) BU[i]->resetObj();
 }

void clam::debug()
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
