#pragma once

#include "osd.h"
#include "mobile.h"
#include "map.h"
#include "particle.h"
#include "flash.h"
#include "fog.h"
#include "water.h"
#include "fire.h"
#include "rain.h"
#include "snow.h"
#include "thunder.h"
#include "bonus.h"
#include "weapon.h"
#include "magic.h"
#include "bullet.h"
#include "player.h"
#include "blade.h"
#include "rockfall.h"
#include "zombie.h"
#include "skeleton.h"
#include "volture.h"
#include "red_arremer.h"
#include "red_arremer_king.h"
#include "plant_mk2.h"
#include "stalagmite.h"
#include "ghost.h"
#include "bat.h"
#include "giant.h"
#include "firewall.h"
#include "insect.h"
#include "fire_grizzly.h"
#include "clam.h"
#include "turtle.h"
#include "demon.h"
#include "little_devil.h"
#include "big_crab.h"
#include "pork.h"
#include "magician.h"
#include "flower.h"
#include "immobile.h"

#define VER "0.56"
#define CFGFILE "config.cfg"
#define FADETIME 18

#define N_STAGE 16
#define N_PLAT 32
#define N_SK 8
#define N_ZO 10
#define N_VO 1
#define N_BL 7
#define N_RF 20
#define N_RA 3
#define N_RK 1
#define N_P2 7
#define N_ST 5
#define N_GO 12
#define N_BA 8
#define N_GI 6
#define N_FW 10
#define N_IN 5
#define N_FG 6
#define N_CL 8
#define N_TU 4
#define N_DE 3
#define N_LD 6
#define N_BC 2
#define N_PO 4
#define N_MA 12
#define N_FL 3
#define N_IMMOBILE 20
#define N_PARFX 240
#define N_WASFX 2
#define N_THSFX 4
#define N_BBOX 12
#define N_BVASE 8

struct BITMAP;
struct MIDI;

class Game {
public:
    bool L_B=1,L_0=1,L_1=1,L_S=1,L_H=1,L_OSD=1,DBUG=1,VSYNC=1;
    int MS=0,OMS=0,FPS=0,fps=0;
    int SCREENRES,SCANLINES,SCREENX,SCREENY,SCREEND,G_RESX,G_RESY,MFPS;
    int MUSIC_VOLUME,SOUND_VOLUME;
    int KEYLEFT,KEYRIGHT,KEYUP,KEYDOWN,KEYJUMP,KEYSHOOT; // Move player keyboard config
    int RESTART_X,RESTART_Y;
    bool FSCREEN,DEBUG,STRETCH;

    int STAGE,LIVES=3,DIFFICULTY=2,READY_GO,SCORE,GAME_OVER,PROLOGUE,INTERLUDE,EPILOGUE,BONUS_SEQ,MIN,SEC,TIME_MS,CKPOINT;
    int MENU_LIVES = LIVES;
    int MAX_STAGE;
    int READY_GO_TIME=80;
    bool TIMEOVER,RETIME;

    BITMAP *VSCR;
private:
    MIDI *music[N_STAGE];

    player           *PL;
    osd              *OSD;
    skeleton         *SK[N_SK];
    zombie           *ZO[N_ZO];
    blade            *BL[N_BL];
    rockfall         *RF[N_RF];
    volture          *VO[N_VO];
    red_arremer      *RA[N_RA];
    red_arremer_king *RK[N_RK];
    plant_mk2        *P2[N_P2];
    stalagmite       *ST[N_ST];
    ghost            *GO[N_GO];
    bat              *BA[N_BA];
    giant            *GI[N_GI];
    firewall         *FW[N_FW];
    insect           *IN[N_IN];
    fire_grizzly     *FG[N_FG];
    clam             *CL[N_CL];
    turtle           *TU[N_TU];
    demon            *DE[N_DE];
    little_devil     *LD[N_LD];
    big_crab         *BC[N_BC];
    pork             *PO[N_PO];
    magician         *MA[N_MA];
    flower           *FL[N_FL];
    immobile         *IMMOBILE[N_IMMOBILE];
    map              *MAP0[N_STAGE],*MAP1[N_STAGE],*MAPH[N_STAGE];
    mobile           **MOBILE;
    particle         *PA_SFX[N_PARFX];
    flash            *FL_SFX;
    fog              *FO_SFX;
    fire             *FI_SFX;
    water            *WA_SFX[N_WASFX];
    rain             *RA_SFX[2];
    snow             *SN_SFX[2];
    thunder          *TH_SFX[N_THSFX];
    bonus            *BONUSB[N_BBOX];
    bonus            *BVASE[N_BVASE];
    bonus            *KEY,*SHILD;
public:
    void init();
    void initEnv();
    void initObjects();
    void initGame(int,int,int);
    void restartStage(int);
    void resetObj();
    void checkGame();
    void readConf(int *,int *,bool *,bool *,bool *,int *,int *,int *,int *,int *,int *,int *,int *);
    void writeConf(int,int,bool,bool,bool,int,int,int,int,int,int,int,int);
    void readyGo();
    void checkTimer();
    void gameOver();
    void Intro();
    void Title();
    void stageMap();
    void layer_back();
    void layer_0();
    void layer_1();
    void layer_s();
    void layer_h();
    void layer_OSD(int);
    void Player();
    void Enemies();
    void Scroll();
    void Collision();
    void collisionPlayerBonus();
    void collisionShildBullets();
    void collisionPlayerEnemies();
    void collisionWeaponEnemies();
    void collisionMagicEnemies();
    void collisionPlayerBullets();
    void rePaint(int);
    void debug(BITMAP *,int);
private:
    void prologue();
    void interlude();
    void epilogue();
};