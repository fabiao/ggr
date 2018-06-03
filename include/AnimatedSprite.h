#pragma once

#include <vector>

struct BITMAP;

class AnimatedSprite {
    public:
        int start_x, start_y;
        int current_x, current_y, current_action, current_frame;
        int ctrl_x, ctrl_y;
        bool enabled;
};

class AnimatedSprites {
    protected:
        BITMAP* screen;
        std::vector<BITMAP*> frames;               // Normal frames
        std::vector<BITMAP*> frames_collision;     // Collision frames
        int src_bmp_rows, src_bmp_cols, frame_width, frame_height;
        std::vector<std::unique_ptr<int*> > timers;
    public:
        void update_scroll_time();
        void animate();
        void draw(int x, int y);
};