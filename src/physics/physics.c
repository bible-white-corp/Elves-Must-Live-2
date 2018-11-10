#include "physics.h"


static float max(float a, float b)
{
    if (a > b)
        return a;
    return b;
}

static float min(float a, float b)
{
    if (a < b)
        return a;
    return b;
}


static int is_between(float a, float borne1, float borne2)
{
    return borne1 < a && a < borne2;
}

int apply_gravity(struct map *map)
{
    struct character **players = map->players;
    size_t n = map->n_players;
    struct vec2 gravity =
    {
        0, ACCELERATION
    };

    for (size_t i = 0; i < n; i++)
        players[i]->velocity = v_sum(players[i]->velocity, gravity);

    return 0;
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


static int is_equal(float a, float b)
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
static int check_col(struct character *player, struct line line)
{
    struct vec2 newpos = player->position;
    struct vec2 v = player->velocity;
    if (v.x > 0)
        newpos.x += player->size.x;
    if (v.y > 0)
        newpos.y += player->size.y;
    struct line dPlayer =
        {
            newpos, v_sum(newpos, player->velocity)
        };
    return is_intersect(dPlayer, line);
}
*/


static int check_col(struct character *player, struct line line)
{
    struct vec2 next = v_sum(player->position, player->velocity);

    if (line.p1.x == line.p2.x) //vertical
    {
        if (is_between(next.y, line.p1.y, line.p2.y)
            || is_between(next.y + player->size.y, line.p1.y, line.p2.y))
            return is_between(line.p1.x, next.x, next.x + player->size.x);
        return 0;
    }

    //horizontal
    if (is_between(next.x, line.p1.x, line.p2.x)
        || is_between(next.x + player->size.x, line.p1.x, line.p2.x))
        return is_between(line.p1.y, next.y, next.y + player->size.y);
    return 0;
}

static struct vec2 find_intersection(struct character *player, struct line l)
{
    struct vec2 hitPlayer = player->position;
    if (player->velocity.x > 0)
        hitPlayer.x += player->size.x;
    if (player->velocity.y > 0)
        hitPlayer.y += player->size.y;

    struct vec2 res =
    {
        0, 0
    };

    struct line dPlayer =
    {
        hitPlayer, v_sum(hitPlayer, player->velocity)
    };
    if (l.p1.x == l.p2.x) //vertical
    {
        res.x = l.p1.x;
        res.y = dPlayer.p1.y / player->position.x * l.p1.x;
    }
    else if (l.p1.y == l.p2.y)
    {
        res.y = l.p1.y;
        res.x = dPlayer.p1.x / player->position.y * l.p1.y;
    }
    return res;
}

static void move(struct character *player)
{
    player->position = v_sum(player->position, player->velocity);
    player->velocity.x *= DRAG;
}


static void move_bounce(struct character *player, struct line l)
{
    if (l.p1.x == l.p2.x) //collide avec un truc vertical
    {
        player->velocity.x *= (-1);
    }
    else
        player->velocity.y *= (-1);
    player->velocity = v_scale(player->velocity, BOUNCE);
    move(player);
}


void move_left(struct character *player)
{
    player->velocity.x = -MOVE_SPEED;
}

void move_right(struct character *player)
{
    player->velocity.x = MOVE_SPEED;
}

void move_jump(struct character *player)
{
    player->velocity.y = -JUMP;
}

int move_all(struct map *map)
{
    struct character **players = map->players;
    size_t n = map->n_players;
    for (size_t i = 0; i < n; i++)
    {
        short collided = 0;
        size_t ndel = map->n_delims;
        for (size_t j = 0; j < ndel; j++)
        {
            struct line delim = map->delims[j];
            if (check_col(players[i], delim) == 0)
                continue;
            move_bounce(players[i], delim);
            collided = 1;
            break;
        }
        if (!collided)
            move(players[i]);
    }
    //return -1 s'il est mort
    //return 1 si gauche
    //return 2 si droite
    return 0;
}


struct line l_create(float a, float b, float c, float d)
{
    struct vec2 v1 =
    {
        b, a
    };
    struct vec2 v2 =
    {
        d, c
    };

    struct line res =
    {
        v1, v2
    };
    return res;
}



struct line *remove_at_i(struct line *list, size_t i, size_t n)
{
    while (i < n - 1)
    {
        list[i] = list[i + 1];
        i++;
    }
    return realloc(list, sizeof(struct line) * (n - 1));
}

void remove_redundancies(struct map *map)
{
    for (size_t i = 0; i < map->n_delims; i++)
    {
        for (size_t j = i + 1; j < map->n_delims; j++)
        {
            if (l_equal(map->delims[i], map->delims[j])
                && l_equal(map->delims[i], map->delims[j]))
            {
                map->delims = remove_at_i(map->delims, j, map->n_delims);
                map->n_delims--;
                map->delims = remove_at_i(map->delims, i, map->n_delims);
                map->n_delims--;
                remove_redundancies(map);
                return;
            }
        }
    }
}


/*
void compute_delims(struct map *map)
{
    size_t nblocks = 0;
    size_t daffile = 0;
    struct vec2 start;

    for (int j = 0; j < WIDTH; j++)
    {
        for (int i = 0; i < HEIGHT; i++)
        {
            if (map->grid[i][j] == GRASS)
            {
                if (!daffile)
                {
                    start.x = i;
                    start.y = j;
                }

                daffile++;
            }
            else
            {
                if (daffile)
                {
                    nblocks += 2;
                    map->delims = realloc(map->delims, sizeof(struct line) * nblocks);
                    map->delims[nblocks - 2] = l_create(start.x, start.y, i, j);
                    map->delims[nblocks - 2] = l_create(start.x, start.y + 1, i, j + 1);
                }
                daffile = 0;
            }
        }
    }

    daffile = 0;


    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (map->grid[i][j] == GRASS)
            {
                if (!daffile)
                {
                    start.x = i;
                    start.y = j;
                }

                daffile++;
            }
            else
            {
                if (daffile)
                {
                    nblocks += 2;
                    map->delims = realloc(map->delims, sizeof(struct line) * nblocks);
                    map->delims[nblocks - 2] = l_create(start.x, start.y, i, j);
                    map->delims[nblocks - 1] = l_create(start.x + 1, start.y, i + 1, j);
                }
                daffile = 0;
            }
        }
    }
    map->n_delims = nblocks;

    remove_redundancies(map);
}
*/
void compute_delims(struct map *map)
{
    size_t nblocks = 0;
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (map->grid[i][j] == GRASS)
            {
                nblocks += 4;
                map->delims = realloc(map->delims, sizeof(struct line) * nblocks);
                map->delims[nblocks - 4] = l_create(i, j, i + 1, j);
                map->delims[nblocks - 3] = l_create(i, j, i, j + 1);
                map->delims[nblocks - 2] = l_create(i + 1, j + 1, i + 1, j);
                map->delims[nblocks - 1] = l_create(i + 1, j + 1, i, j + 1);
            }
        }
    }

    map->n_delims = nblocks;
/*
    for (size_t i = 0; i < map->n_delims; i++)
    {
        printf("delims[%ld] : (%.0f %.0f) (%.0f %.0f)\n", i, map->delims[i].p1.x, map->delims[i].p1.y, map->delims[i].p2.x, map->delims[i].p2.y);
    }

    printf("\n\n\n");
*/
    remove_redundancies(map);
/*
    for (size_t i = 0; i < map->n_delims; i++)
    {
        printf("delims[%ld] : (%.0f %.0f) (%.0f %.0f)\n", i, map->delims[i].p1.x, map->delims[i].p1.y, map->delims[i].p2.x, map->delims[i].p2.y);
    }
*/
}
