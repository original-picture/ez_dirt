
#include "ez_dirt_dsp.h"

#include "ez_math.h"

#include <cmath>

float hard_clip_antiderivative(float x) {
    if(x <= -1.f) {
        return -x - .5f;
    }
    else if(x >= 1.f) {
        return  x - .5f;
    }
    else {
        return .5f*x*x;
    }
}

clipping_func_t clipping_funcs[] = {arctan_clip, tanh_clip, rounded_hard_clip, digital_hard_clip};

float arctan_clip(float x) {
    return 2.f*atan(x)/ez::fpi;
}

float tanh_clip(float x) {
    return tanh(x);
}

float rounded_hard_clip(float x) {
    float softness = 1.f;
    return (hard_clip_antiderivative(x+softness)-hard_clip_antiderivative(x-softness))/(2.f*softness);
}

float digital_hard_clip(float x) {
    return ez::clamp(x);
}
