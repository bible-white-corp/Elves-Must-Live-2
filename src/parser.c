#include <stdio.h>
#include <stdlib.h>
#include "eml2.h"

void map_parse(char *path, struct map *map)
{
    char cur;
    FILE *f = fopen(path, "r");
    char **grid = malloc(sizeof(char*) * HEIGHT);
    for (int j = 0; j < HEIGHT; j++)
    {
        grid[j] = malloc(sizeof(char) * WIDTH);
        for (int i = 0; i < WIDTH + 1; i++)
        {
            fread(&cur, 1, 1, f);
            if (cur == '\n' || cur == EOF)
                break;
            grid[j][i] = cur;
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


void map_print(struct map *map)
{
    printf("MAP:\n");
    for (int j = 0; j < HEIGHT; j++)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            printf("%c", map->grid[j][i]);
        }
        printf("\n");
    }
}

int main(void)
{
    struct map map =
    {
        NULL
    };
    map_parse("map.eml", &map);
    map_print(&map);
    map_delete(&map);
}
