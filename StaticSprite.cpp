#include "include/StaticSprite.h"
#include <allegro.h>
#include <cstdio>

StaticSprite::StaticSprite() {

}

StaticSprite::~StaticSprite() {
    unload_frames();
}

void StaticSprite::load_frames(const char* base_frame_file_name, const char* aux_frame_file_name) {
    auto s = ::load_sample(base_frame_file_name);
    if (s != NULL) {
        base_frame = s;
        printf("Loaded sample: %s", file_name);
    } else {
        printf("Error loading sample: %s", file_name);
    }     
}

void Sampled::unload_frames() {
    if (::destroy_bitmap(water_bmp);
    ::destroy_bitmap(aux_bmp);((*s)->internal);
    samples.clear();
}

void StaticSprite::update_scroll_time() {

}

void StaticSprite::draw(int x, int y) {

}