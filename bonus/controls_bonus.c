#include "../so_long_bonus.h"

static void	move_up(t_mapb *map)
{
	int	x;
	int	y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->plan[y - 1][x] != '1')
	{
		coinb(map, y - 1, x);
		if (map->plan[y][x] != 'E')
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.back.img, 32 * x, 32 * y);
		else
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.door_c.img, 32 * x, 32 * y);
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.player.img, 32 * x, 32 * (y - 1));
		doorb(map, y - 1, x);
		map->pos_y--;
		map->count++;
	}
}

static void	move_left(t_mapb *map)
{
	int	x;
	int	y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->plan[y][x - 1] != '1')
	{
		coinb(map, y, x - 1);
		if (map->plan[y][x] != 'E')
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.back.img, 32 * x, 32 * y);
		else
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.door_c.img, 32 * x, 32 * y);
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.player.img, 32 * (x - 1), 32 * y);
		doorb(map, y, x - 1);
		map->pos_x--;
		map->count++;
	}
}

static void	move_right(t_mapb *map)
{
	int	x;
	int	y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->plan[y][x + 1] != '1')
	{
		coinb(map, y, x + 1);
		if (map->plan[y][x] != 'E')
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.back.img, 32 * x, 32 * y);
		else
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.door_c.img, 32 * x, 32 * y);
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.player.img, 32 * (x + 1), 32 * y);
		doorb(map, y, x + 1);
		map->pos_x++;
		map->count++;
	}
}

static void	move_down(t_mapb *map)
{
	int		x;
	int		y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->plan[y + 1][x] != '1')
	{
		coinb(map, y + 1, x);
		if (map->plan[y][x] != 'E')
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.back.img, 32 * x, 32 * y);
		else
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.door_c.img, 32 * x, 32 * y);
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.player.img, 32 * x, 32 * (y + 1));
		doorb(map, y + 1, x);
		map->pos_y++;
		map->count++;
	}
}

int	controlsb(int keycode, t_mapb *map)
{
	if (keycode == 53)
		ft_destroyb(map);
	else if (keycode == 13)
		move_up(map);
	else if (keycode == 0)
		move_left(map);
	else if (keycode == 1)
		move_down(map);
	else if (keycode == 2)
		move_right(map);
	return (1);
}
