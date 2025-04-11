#include "../includes/cub3d.h"

char **get_map(void)
{
    char **map = malloc(sizeof(char *) * 11);
    if (!map)
        return (NULL);

    // Define o labirinto (19 colunas x 10 linhas + NULL)
    map[0] = "1111111111111111111";
    map[1] = "1000000000111000011";
    map[2] = "1000000000000000001";
    map[3] = "1000000010000000001";
    map[4] = "1000000000000000001";
    map[5] = "1000000000010000001";
    map[6] = "1000000100000000001";
    map[7] = "1000000000000100001";
    map[8] = "1000000000000000001";
    map[9] = "1111111111111111111";
    map[10] = NULL;
    
    return (map);
}

void draw_map(t_data *data)
{
    char **map = data->map;
    int wall_color = 0xFFFF00;  // Amarelo para paredes
    int y = -1;
    int x;

    while (map[++y])
    {
        x = -1;
        while (map[y][++x])
        {
            if (map[y][x] == '1')
                draw_square(x * BLOCK, y * BLOCK, BLOCK, wall_color, data);
            // Adicione aqui outros caracteres (ex: '0' para chão, 'P' para jogador)
        }
    }
}
