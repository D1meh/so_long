#include "../so_long_bonus.h"

void	ft_openb(t_mapb *map, char *file)
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

int	ft_destroyb(t_mapb *map)
{
	int	i;

	free_split(map->plan);
	i = 0;
	if (map->enemies)
	{
		while (i < map->enemies)
		{
			free(map->enemy[i]);
			i++;
		}
		free(map->enemy);
	}
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}

void	enemy_contact(t_mapb *map)
{
	int	n;

	n = 0;
	while (n < map->enemies)
	{
		if (map->pos_x == map->enemy[n][0] && map->pos_y == map->enemy[n][1])
		{
			write(1, "Ouch ! That hurts...\n", 21);
			ft_destroyb(map);
		}
		n++;
	}
}
