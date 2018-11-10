#pragma once

#include "eml2.h"

struct inputs
{
    short left;
    short right;
    short jump;
    short quit;
};


struct inputs get_inputs(void);
int update(struct game *game, struct inputs in);
