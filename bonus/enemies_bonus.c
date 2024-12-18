#include "../so_long_bonus.h"

static void	enemy_location(t_mapb *map, int *i, int *j)
{
	while (map->plan[*i])
	{
		if (map->plan[*i][*j] == '2')
			return ;
		if (map->plan[*i][*j] == 0)
		{
			*j = 0;
			*i = *i + 1;
			continue ;
		}
		*j = *j + 1;
	}
}

void	enemies(t_mapb *map)
{
	int	i;
	int	j;
	int	n;

	if (!map->enemies)
		return ;
	map->enemy = malloc(sizeof(int *) * map->enemies);
	n = 0;
	i = 0;
	j = 0;
	while (n < map->enemies)
	{
		map->enemy[n] = malloc(sizeof(int) * 3);
		enemy_location(map, &i, &j);
		map->enemy[n][0] = j;
		map->enemy[n][1] = i;
		map->enemy[n][2] = 1;
		j++;
		n++;
	}
}

void	updown_enemy(t_mapb *map, int n)
{
	int	x;
	int	y;

	x = map->enemy[n][0];
	y = map->enemy[n][1];
	if ((map->plan[y - 1][x] == '1' && map->enemy[n][2])
		|| (map->plan[y + 1][x] == '1' && !map->enemy[n][2]))
		map->enemy[n][2] = 1 - map->enemy[n][2];
	if (map->enemy[n][2])
	{
		map->enemy[n][1]--;
		put_if(map->graph.koopa.img, x, y - 1, map);
	}
	else
	{
		map->enemy[n][1]++;
		put_if(map->graph.koopa_r.img, x, y + 1, map);
	}
}

void	leftright_enemy(t_mapb *map, int n)
{
	int	x;
	int	y;

	x = map->enemy[n][0];
	y = map->enemy[n][1];
	if ((map->plan[y][x - 1] == '1' && map->enemy[n][2])
		|| (map->plan[y][x + 1] == '1' && !map->enemy[n][2]))
		map->enemy[n][2] = 1 - map->enemy[n][2];
	if (map->enemy[n][2])
	{
		map->enemy[n][0]--;
		put_if(map->graph.koopa.img, x - 1, y, map);
	}
	else
	{
		map->enemy[n][0]++;
		put_if(map->graph.koopa_r.img, x + 1, y, map);
	}
}

int	enemy_movement(t_mapb *map)
{
	int	i;

	if (!map->enemies)
		return (1);
	i = 0;
	while (i < map->enemies)
	{
		if (i % 2 == 0)
			updown_enemy(map, i);
		else
			leftright_enemy(map, i);
		i++;
	}
	return (1);
}
