#pragma once

#include <vector>

struct SAMPLE;

struct Sample {
    SAMPLE* internal;
    int vol, pan, freq, loop;
};

class Sampled {
    protected:
        std::vector<Sample*> samples;

    public:
        Sampled();
        ~Sampled();
        void load_sample(const char* file_name, int vol, int pan, int freq, int loop);
        void unload_samples();
        void play_sample(int index);
};