#pragma once

struct BITMAP;

class StaticSprite {
    protected:
        BITMAP* screen;
        BITMAP* base_frame;
        BITMAP* aux_frame;
    public:
        StaticSprite();
        ~StaticSprite();
        void load_frames(const char* base_frame_file_name, const char* aux_frame_file_name);
        void unload_frames();
        void update_scroll_time();
        void draw(int x, int y);
};