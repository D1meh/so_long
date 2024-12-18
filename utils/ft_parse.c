#include "../so_long.h"

static char	**get_map(t_map *mp)
{
	char	*tmp;
	char	*map;
	char	buf[BUFFER_SIZE + 1];
	int		n;
	char	**split;

	n = read(mp->fd, buf, BUFFER_SIZE);
	if (n < 1)
		print_error(4);
	map = ft_strdup("");
	while (n)
	{
		buf[n] = 0;
		tmp = ft_strjoin(map, buf);
		free(map);
		map = tmp;
		n = read(mp->fd, buf, BUFFER_SIZE);
	}
	ft_strchr(map);
	split = ft_split(map, '\n');
	free(map);
	close(mp->fd);
	return (split);
}

static int	check_len(char **split)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(split[0]);
	while (split[i])
	{
		if (len != ft_strlen(split[i]))
			split_error(split, 5);
		i++;
	}
	return (len);
}

static void	check_walls(char **split)
{
	int		i;
	int		len;

	if (!ft_only1(split[0]) || !ft_only1(split[split_len(split) - 1]))
		split_error(split, 6);
	len = check_len(split);
	i = 1;
	while (split[i])
	{
		if (split[i][0] != '1' || split[i][len - 1] != '1')
			split_error(split, 6);
		i++;
	}
}

static void	fill_struct(char **split, t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (split[i])
	{
		j = 1;
		while (split[i][j])
		{
			if (split[i][j] == 'E')
				map->exit = 1;
			else if (split[i][j] == 'P')
				map->start++;
			else if (split[i][j] == 'C')
				map->collec++;
			else if (split[i][j] != '1' && split[i][j] != '0')
				split_error(split, 7);
			j++;
		}
		i++;
	}
}

void	ft_parse(t_map *map)
{
	map->plan = get_map(map);
	check_walls(map->plan);
	fill_struct(map->plan, map);
	if (!map->exit)
		split_error(map->plan, 8);
	if (!map->collec)
		split_error(map->plan, 9);
	if (!map->start)
		split_error(map->plan, 10);
	if (map->start > 1)
		split_error(map->plan, 11);
	if (ft_strlen(map->plan[0]) < 41)
		map->width = 32 * ft_strlen(map->plan[0]);
	else
		map->width = 1312;
	if (split_len(map->plan) < 27)
		map->height = 32 * split_len(map->plan);
	else
		map->height = 864;
}
