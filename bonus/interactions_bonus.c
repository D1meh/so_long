#include "../so_long_bonus.h"

/*static void	get_door_location(t_mapb *map, int *door_x, int *door_y)
{
	int	i;
	int	j;

	i = 1;
	while (map->plan[i])
	{
		j = 1;
		while (map->plan[i][j])
		{
			if (map->plan[i][j] == 'E')
			{
				*door_x = j;
				*door_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}*/

void	coinb(t_mapb *map, int y, int x)
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

void	doorb(t_mapb *map, int y, int x)
{
	if (map->plan[y][x] == 'E')
	{
		if (!map->done)
			write(1, "There are still some collectibles !\n", 36);
		else
		{
			write(1, "Congratulations !\n", 18);
			ft_destroyb(map);
		}
	}
}
