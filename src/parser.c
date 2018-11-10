#include <stdio.h>
#include <stdlib.h>
#include "eml2.h"

void map_parse(char *path, struct map *map)
{
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
