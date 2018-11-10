#pragma once

#include "eml2.h"
#include <math.h>

#define ACCELERATION 0.02f
#define BOUNCE 0.2f
#define EPSILON 0.000001f
#define MOVE_SPEED 0.5f
#define JUMP 0.2f
#define DRAG 0.97f
int apply_gravity(struct map *map);
int move_all(struct map *map);

int is_intersect(struct line l1, struct line l2);
void compute_delims(struct map *map);

void move_left(struct character *player);
void move_right(struct character *player);
void move_jump(struct character *player);

