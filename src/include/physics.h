#pragma once

#include "eml2.h"
#include <math.h>

#define ACCELERATION 0.1f
#define BOUNCE 0.7f
#define EPSILON 0.0001f
#define MOVE_SPEED 1
#define JUMP 4

int apply_gravity(struct map *map);
int move_all(struct map *map);

int is_intersect(struct line l1, struct line l2);

void move_left(struct character *player);
void move_right(struct character *player);
void move_jump(struct character *player);
