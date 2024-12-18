#include "../so_long_bonus.h"

static void	get_chunk(t_mapb *map)
{
	map->chunk_x = map->pos_x / 41;
	map->chunk_y = map->pos_y / 27;
}

static void	put_texture(t_mapb *map, int i, int j)
{
	if (i != 0 && j != 0 && i != split_len(map->plan) - 1
		&& j != ft_strlen(map->plan[0]) - 1)
		put_imageb(map->graph.back.img, i % 27, j % 41, map);
	if (map->plan[i][j] == '1')
		put_imageb(map->graph.wall.img, i % 27, j % 41, map);
	else if (map->plan[i][j] == 'C')
		putcoinb(i % 27, j % 41, map);
	else if (map->plan[i][j] == 'E')
	{
		if (map->done)
			put_imageb(map->graph.door_o.img, i % 27, j % 41, map);
		else
			put_imageb(map->graph.door_c.img, i % 27, j % 41, map);
	}
	put_imageb(map->graph.player.img, map->pos_y % 27, map->pos_x % 41, map);
}

static void	finish_line(t_mapb *map, int i, int j)
{
	while (j < (map->chunk_x + 1) * 41)
	{
		put_imageb(map->graph.black.img, i % 27, j % 41, map);
		j++;
	}
}

static void	finish_square(t_mapb *map, int i, int j)
{
	while (i < (map->chunk_y + 1) * 27)
	{
		j = map->chunk_x * 41;
		while (j < (map->chunk_x + 1) * 41)
		{
			put_imageb(map->graph.black.img, i % 27, j % 41, map);
			j++;
		}
		i++;
	}
}

void	write_imageb(t_mapb *map)
{
	int	i;
	int	j;

	create_textureb(&map->graph, map);
	get_chunk(map);
	i = map->chunk_y * 27;
	while (i < (map->chunk_y + 1) * 27)
	{
		if (map->plan[i] == 0)
			return (finish_square(map, i, j));
		j = map->chunk_x * 41;
		while (j < (map->chunk_x + 1) * 41)
		{
			if (map->plan[i][j] == 0)
			{
				finish_line(map, i, j);
				break ;
			}
			put_texture(map, i, j);
			j++;
		}
		i++;
	}
}
