#include "so_long.h"

static void	starting_position(t_map *map)
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

static void	init_struct(t_map *map)
{
	map->collec = 0;
	map->start = 0;
	map->exit = 0;
	map->count = 0;
	map->done = 0;
}

int	main(int ac, char **av)
{
	t_map		map;

	if (ac != 2)
		print_error(1);
	ft_open(&map, av[1]);
	init_struct(&map);
	ft_parse(&map);
	starting_position(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width, map.height, "so_long");
	write_image(&map);
	mlx_hook(map.win, 17, 0, ft_destroy, &map);
	mlx_key_hook(map.win, controls, &map);
	mlx_loop(map.mlx);
	return (0);
}
