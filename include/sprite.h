#pragma once

struct BITMAP;

class sprite
 {
  protected:
   int start_x,start_y;
   int X,Y;
   int index;
   int action;
   int rows,columns,width,height; // Sprite frame size in bitmap file
   int act_frame;                 // Sprite current frame
   bool enabled;
   BITMAP *screen;
   BITMAP **frames;               // Normal frames
   BITMAP **frames_collision;     // Collision frames

  public:
   sprite(const char *,BITMAP *,int,int,int,sprite *);
   ~sprite();
   void loadSprite(const char *,sprite *);
   void loadData(const char *);
   void loadFrames(const char *);
   void setStartX(int);
   void setStartY(int);
   void setX(int);
   void setY(int);
   void setCurrentFrame(int);
   void setScreen(BITMAP *);
   int getRows();
   int getColumns();
   int getWidth();
   int getHeight();
   int getX();
   int getY();
   int getCurrentFrame();
   BITMAP *getFrame(int);
   bool isEnabled();
 };
