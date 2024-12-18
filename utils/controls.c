#include "../so_long.h"

static void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->plan[y - 1][x] != '1')
	{
		coin(map, y - 1, x);
		if (map->plan[y][x] != 'E')
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.back.img, 32 * x, 32 * y);
		else
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.door_c.img, 32 * x, 32 * y);
		door(map, y - 1, x);
		map->pos_y--;
		map->count++;
		ft_putnbr(map->count);
		write(1, "\n", 1);
	}
}

static void	move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->plan[y][x - 1] != '1')
	{
		coin(map, y, x - 1);
		if (map->plan[y][x] != 'E')
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.back.img, 32 * x, 32 * y);
		else
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.door_c.img, 32 * x, 32 * y);
		door(map, y, x - 1);
		map->pos_x--;
		map->count++;
		ft_putnbr(map->count);
		write(1, "\n", 1);
	}
}

static void	move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->plan[y][x + 1] != '1')
	{
		coin(map, y, x + 1);
		if (map->plan[y][x] != 'E')
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.back.img, 32 * x, 32 * y);
		else
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.door_c.img, 32 * x, 32 * y);
		door(map, y, x + 1);
		map->pos_x++;
		map->count++;
		ft_putnbr(map->count);
		write(1, "\n", 1);
	}
}

static void	move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->pos_x;
	y = map->pos_y;
	if (map->plan[y + 1][x] != '1')
	{
		coin(map, y + 1, x);
		if (map->plan[y][x] != 'E')
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.back.img, 32 * x, 32 * y);
		else
			mlx_put_image_to_window(map->mlx, map->win,
				map->graph.door_c.img, 32 * x, 32 * y);
		door(map, y + 1, x);
		map->pos_y++;
		map->count++;
		ft_putnbr(map->count);
		write(1, "\n", 1);
	}
}

int	controls(int keycode, t_map *map)
{
	if (keycode == 53)
		ft_destroy(map);
	else if (keycode == 13)
		move_up(map);
	else if (keycode == 0)
		move_left(map);
	else if (keycode == 1)
		move_down(map);
	else if (keycode == 2)
		move_right(map);
	write_image(map);
	return (1);
}
