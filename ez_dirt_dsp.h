
#pragma once

float arctan_clip(float x);
float tanh_clip(float x);
float rounded_hard_clip(float x);
float digital_hard_clip(float x);

using clipping_func_t = float(*)(float);

extern clipping_func_t clipping_funcs[];