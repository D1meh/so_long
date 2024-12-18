#include "../so_long.h"

void	create_texture(t_graph *graph, t_map *game)
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
	graph->black.img = mlx_xpm_file_to_image(game->mlx, "images/black.xpm",
			&graph->black.width, &graph->black.height);
}

void	put_image(void *texture, int i, int j, t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, texture, 32 * j, 32 * i);
}

void	putcoin(void *texture, int i, int j, t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win,
		texture, 32 * j + 8, 32 * i + 4);
}
