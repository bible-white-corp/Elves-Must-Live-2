#include <stdio.h>
#include <stdlib.h>
#include "eml2.h"

static void add_player(int i, int j, struct map *map)
{
    map->players[map->n_players]->position = { i, j };
    map->n_players++;
}

void map_parse(char *path, struct map *map)
{
    map->n_players = 0;
    map->players = malloc(sizeof(struct characters*) * 20);
    char cur;
    FILE *f = fopen(path, "r");
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
                case 'p':
                    grid[j][i] = VOID;
                    add_player(i, j, map);
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

void map_delete(struct map *map)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        free(map->grid[i]);
    }
    free(map->grid);
}
