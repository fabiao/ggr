#include "include/Sampled.h"
#include <allegro.h>
#include <cstdio>

Sampled::Sampled() {

}

Sampled::~Sampled() {
    unload_samples();
}

 void Sampled::load_sample(const char* file_name, int vol, int pan, int freq, int loop) {
    auto s = ::load_sample(file_name);
    if (s != NULL) {
        samples.push_back(new Sample { s, vol, pan, freq, loop });
        printf("Loaded sample: %s", file_name);
    } else {
        printf("Error loading sample: %s", file_name);
    }     
 }

 void Sampled::unload_samples() {
    for(auto s = samples.begin(); s != samples.end(); ++s)    {
        ::destroy_sample((*s)->internal);
        delete *s;
    }
    samples.clear();
 }

 void Sampled::play_sample(int index) {
    if (index < samples.size()) {
        //int play_sample(const SAMPLE *spl, int vol, int pan, int freq, int loop)
        //Triggers a sample at the specified volume, pan position, and frequency.
        //The parameters `vol' and `pan' range from 0 (min/left) to 255 (max/right).
        //Frequency is relative rather than absolute: 1000 represents the frequency that the sample was recorded at, 2000 is twice this, etc.
        //If `loop' is not zero, the sample will repeat until you call stop_sample(), and can be manipulated while it is playing by calling adjust_sample(). 
        auto sample = samples[index];
        ::play_sample(sample->internal,sample->vol,sample->pan,sample->freq,sample->loop);
    }
 }