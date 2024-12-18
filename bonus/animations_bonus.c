#include "../so_long_bonus.h"

/*static void	put_coin(t_mapb *map, int i, int j, int n)
{
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
}*/

/*void	coin_animation(t_mapb *map)
{
	static int	n = 2;
	int			i;
	int			j;
	int			cpt;

	i = 0;
	while (map->plan[i])
	{
		j = 0;
		while (map->plan[i][j])
		{
			if (map->plan[i][j] == 'C')
				putcoinb(i, j, map);
			j++;
		}
		i++;
	}
	cpt = 0;
	while (cpt < 25000000)
		cpt++;
	n++;
}*/

void	ft_putcount(t_mapb *map, int n)
{
	char		*nb;
	void		*black;

	nb = ft_itoa(n);
	black = mlx_xpm_file_to_image(map->mlx, "./images/black.xpm",
			&map->graph.coin4.width, &map->graph.coin4.height);
	if (split_len(map->plan) < 27)
	{
		mlx_put_image_to_window(map->mlx, map->win, black, 200, 844);
		mlx_put_image_to_window(map->mlx, map->win, black, 232, 844);
		mlx_put_image_to_window(map->mlx, map->win, black, 264, 844);
		mlx_put_image_to_window(map->mlx, map->win, black, 296, 844);
	}
	mlx_string_put(map->mlx, map->win, 10, map->height - 20,
		255255255, "Movement count :");
	mlx_string_put(map->mlx, map->win, 200, map->height - 20, 255255255, nb);
	free(nb);
}

int	animation(t_mapb *map)
{
	int	cpt;

	write_imageb(map);
	ft_putcount(map, map->count);
	enemy_movement(map);
	enemy_contact(map);
	cpt = 0;
	while (cpt < 25000000)
		cpt++;
	return (1);
}
