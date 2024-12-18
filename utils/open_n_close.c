#include "../so_long.h"

void	ft_open(t_map *map, char *file)
{
	if (!ft_strstr(file, ".ber"))
		print_error(2);
	map->fd = open(file, O_DIRECTORY);
	if (map->fd != -1)
		print_error(3);
	map->fd = open(file, O_RDONLY);
	if (map->fd == -1)
		print_error(3);
}

int	ft_destroy(t_map *map)
{
	free_split(map->plan);
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}
