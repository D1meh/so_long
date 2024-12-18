#include "../so_long_bonus.h"

void	create_textureb(t_graphb *graph, t_mapb *game)
{
	graph->wall.img = mlx_xpm_file_to_image(game->mlx, "./images/rock32.xpm",
			&graph->wall.width, &graph->wall.height);
	graph->coin.img = mlx_xpm_file_to_image(game->mlx, "./images/coin.xpm",
			&graph->coin.width, &graph->coin.height);
	graph->back.img = mlx_xpm_file_to_image(game->mlx, "./images/back32.xpm",
			&graph->back.width, &graph->back.height);
	graph->door_c.img = mlx_xpm_file_to_image(game->mlx, "images/door.xpm",
			&graph->door_c.width, &graph->door_c.height);
	graph->player.img = mlx_xpm_file_to_image(game->mlx, "images/yoshi.xpm",
			&graph->player.width, &graph->player.height);
	graph->door_o.img = mlx_xpm_file_to_image(game->mlx, "images/door_o.xpm",
			&graph->door_o.width, &graph->door_c.height);
	graph->coin2.img = mlx_xpm_file_to_image(game->mlx, "./images/coin2.xpm",
			&graph->coin2.width, &graph->coin2.height);
	graph->coin3.img = mlx_xpm_file_to_image(game->mlx, "./images/coin3.xpm",
			&graph->coin3.width, &graph->coin3.height);
	graph->coin4.img = mlx_xpm_file_to_image(game->mlx, "./images/coin4.xpm",
			&graph->coin4.width, &graph->coin4.height);
	graph->koopa.img = mlx_xpm_file_to_image(game->mlx, "images/koopa.xpm",
			&graph->koopa.width, &graph->koopa.height);
	graph->koopa_r.img = mlx_xpm_file_to_image(game->mlx, "images/koopa_r.xpm",
			&graph->koopa_r.width, &graph->koopa_r.width);
	graph->black.img = mlx_xpm_file_to_image(game->mlx, "images/black.xpm",
			&graph->black.width, &graph->black.height);
}

void	putcoinb(int i, int j, t_mapb *map)
{
	static int	n = 0;

	if (n % 8 == 2 || n % 8 == 3)
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin2.img, 32 * j + 8, 32 * i + 4);
	else if (n % 8 == 4 || n % 8 == 5)
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin3.img, 32 * j + 8, 32 * i + 4);
	else if (n % 8 == 0 || n % 8 == 1)
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin4.img, 32 * j + 8, 32 * i + 4);
	else
		mlx_put_image_to_window(map->mlx, map->win,
			map->graph.coin.img, 32 * j + 8, 32 * i + 4);
	n++;
}

void	put_imageb(void *texture, int i, int j, t_mapb *map)
{
	mlx_put_image_to_window(map->mlx, map->win, texture, 32 * j, 32 * i);
}

void	put_if(void *texture, int x, int y, t_mapb *map)
{
	if (x >= map->chunk_x * 41 && x <= (map->chunk_x + 1) * 41
		&& y >= map->chunk_y * 27 && y <= (map->chunk_y + 1) * 27)
	{
		mlx_put_image_to_window(map->mlx, map->win, texture, (x % 41) * 32 + 8,
			(y % 27) * 32 + 3);
	}
}
