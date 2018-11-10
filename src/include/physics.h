#pragma once

#include "eml2.h"
#include <math.h>

#define ACCELERATION 0.1f
#define BOUNCE 0.2f
#define EPSILON 0.0001f
struct line
{
    struct vec2 p1;
    struct vec2 p2;
};


struct vec2 check_col(struct vec2 pos1, struct vec2 pos2, struct vec2 a, struct vec2 b);
int apply_gravity(struct character **players, size_t n);
int is_intersect(struct line l1, struct line l2);
