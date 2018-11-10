#include "physics.h"


float max(float a, float b)
{
    if (a > b)
        return a;
    return b;
}

float min(float a, float b)
{
    if (a < b)
        return a;
    return b;
}

//opti: l'écrire en une ligne
static int on_line(struct line l1, struct vec2 p)
{
    int b1 = p.x <= max(l1.p1.x, l1.p2.x) && p.x <= min(l1.p1.x, l1.p2.x);
    int b2 = p.y <= max(l1.p1.y, l1.p2.y);
    return b1 && b2 && p.y <= min(l1.p1.y, l1.p2.y);
}


static int dir_points(struct vec2 a, struct vec2 b, struct vec2 c)
{
    float det = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

    if (fabs(det) < EPSILON)
        return 0;
    return (det < 0) + 1;
}


int is_equal(float a, float b)
{
    return a - EPSILON < b && a + EPSILON > b;
}

int is_intersect(struct line l1, struct line l2)
{
    int dir1 = dir_points(l1.p1, l1.p2, l2.p1);
    int dir2 = dir_points(l1.p1, l1.p2, l2.p2);
    int dir3 = dir_points(l2.p1, l2.p2, l1.p1);
    int dir4 = dir_points(l2.p1, l2.p2, l1.p2);

    if ((!is_equal(dir1, dir2) && !is_equal(dir3, dir4))
        || (!dir1 && on_line(l1, l2.p1))
        || (!dir2 && on_line(l1, l2.p1))
        || (!dir3 && on_line(l2, l1.p1))
        || (!dir4 && on_line(l2, l1.p2)))
        return 1;
    return 0;
}


/*
int check_col(struct vec2 pos1, struct vec2 pos2, struct vec2 a, struct vec2 b)
{
    if (a.x == b.x && ) // horizontal
        return (pos1.x > a.x) != (pos2.x > a.x);
    else // vertical
        return (pos1.y > a.y) != (pos2.y > a.y);
    }
}
*/
int apply_gravity(struct character **players, size_t n)
{
    struct vec2 gravity =
    {
        0, ACCELERATION
    };

    for (size_t i = 0; i < n; i++) //gravity
    {
        struct vec2 newpos = v_sum(players[i]->velocity, gravity);
        newpos = newpos;
        
    }

    return 0;
}
