#include "so_long_bonus.h"

static void	starting_position(t_mapb *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->plan[i])
	{
		j = 0;
		while (map->plan[i][j])
		{
			if (map->plan[i][j] == 'P')
			{
				map->pos_x = j;
				map->pos_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	init_struct(t_mapb *map)
{
	map->collec = 0;
	map->start = 0;
	map->exit = 0;
	map->count = 0;
	map->done = 0;
	map->enemies = 0;
}

int	main(int ac, char **av)
{
	t_mapb		map;

	if (ac != 2)
		print_error(1);
	ft_openb(&map, av[1]);
	init_struct(&map);
	ft_parseb(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width, map.height, "so_long");
	starting_position(&map);
	write_imageb(&map);
	enemies(&map);
	mlx_hook(map.win, 17, 0, ft_destroyb, &map);
	mlx_key_hook(map.win, controlsb, &map);
	mlx_loop_hook(map.mlx, animation, &map);
	mlx_loop(map.mlx);
	return (0);
}
