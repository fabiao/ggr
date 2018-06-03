#pragma once

struct BITMAP;

#define LANCE 0
#define KNIFE 1
#define AXE   2
#define SWORD 3
#define ARROW 4
#define FLAME 5

void count();

int AR_Clock();

void wait(int ms);

int random(int max) ;

void fade32(BITMAP *bmp);

bool hitTest8(BITMAP *obj1,BITMAP *obj2,int x1,int y1,int x2,int y2);

bool hitTestFast8(BITMAP *obj1,BITMAP *obj2,int x1,int y1,int x2,int y2,int step=7,int ssx=12,int ssy=5,bool side=0);

bool hitTest24(BITMAP *obj1,BITMAP *obj2,int x1,int y1,int x2,int y2);

int angle2P(int x0,int y0,int x1,int y1);

void drawBar(int per, int col, int w);

// Posteffects (experimental)
void _scanline(BITMAP *bmp, int sl);
