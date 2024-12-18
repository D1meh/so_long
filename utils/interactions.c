#include "../so_long.h"

void	coin(t_map *map, int y, int x)
{
	if (map->plan[y][x] == 'C')
	{
		map->collec--;
		map->plan[y][x] = '0';
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.back.img, 32 * x, 32 * y);
		if (!map->collec)
			map->done = 1;
	}
}

void	door(t_map *map, int y, int x)
{
	if (map->plan[y][x] == 'E')
	{
		if (!map->done)
			write(1, "There are still some collectibles !\n", 36);
		else
		{
			write(1, "Congratulations !\n", 18);
			ft_destroy(map);
		}
	}
}
