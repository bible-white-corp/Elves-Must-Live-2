#include <stdio.h>
#include <stdlib.h>
#include "eml2.h"
#include <err.h>

void map_delete(struct map *map)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        free(map->grid[i]);
    }
    // FREE PLAYERS
    for (size_t i = 0; i < map->n_players; i++)
        free(map->players[i]);
    free(map->grid);
}

static void add_player(int i, int j, struct map *map, short is_player)
{
    struct vec2 pos =
    {
        i, j
    };
    struct vec2 size =
    {
        1, 2
    };

    int cur = map->n_players;
    if (is_player)
    {
        cur = 0;
    }
    else
        map->n_players++;

    map->players[cur] = malloc(sizeof(struct character));
    map->players[cur]->position = pos;
    map->players[cur]->size = size;
    map->players[cur]->map = map;
    map->players[cur]->is_ground = 1;
    map->players[cur]->orientation = 1;
    map->players[cur]->is_dead = 0;
    map->players[cur]->is_attacking = 0;
    if (is_player)
        map->players[0]->is_player = 1;
}

void map_parse(char *path, struct map *map)
{
    if (map->grid)
        map_delete(map);
    map->n_players = 1;
    map->players = malloc(sizeof(struct character*) * 20);
    char cur;
    FILE *f = fopen(path, "r");
    if (!f)
        err(1, "Cannot open %s", path);
    enum block **grid = malloc(sizeof(enum block*) * HEIGHT);
    for (int j = 0; j < HEIGHT; j++)
    {
        grid[j] = malloc(sizeof(enum block) * WIDTH);
        for (int i = 0; i < WIDTH + 1; i++)
        {
            fread(&cur, 1, 1, f);
            if (cur == '\n' || cur == EOF)
                break;
            switch (cur)
            {
                case 'b':
                    grid[j][i] = VOID;
                    break;
                case 'w':
                    grid[j][i] = GRASS;
                    break;
                case 'l':
                    grid[j][i] = LAVA;
                    break;
                case 'p':
                    grid[j][i] = VOID;
                    add_player(i, j, map, 1);
                    break;
                case 'e':
                    grid[j][i] = VOID;
                    add_player(i, j, map, 0);
                    break;
                default:
                    grid[j][i] = VOID;
                    break;
            }
        }
        if (cur == EOF)
            break;
    }
    fclose(f);
    map->grid = grid;
}


