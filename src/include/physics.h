#pragma once

#include "eml2.h"
#include <math.h>

#define ACCELERATION 0.01f
#define BOUNCE 0.7f
#define EPSILON 0.0001f
#define MOVE_SPEED 0.2f
#define JUMP 0.5f
#define DRAG 0.95f
int apply_gravity(struct map *map);
int move_all(struct map *map);

int is_intersect(struct line l1, struct line l2);
void compute_delims(struct map *map);

void move_left(struct map *map);
void move_right(struct map *map);
void move_jump(struct map *map);
