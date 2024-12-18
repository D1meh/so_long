/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:20:12 by mtaouil           #+#    #+#             */
/*   Updated: 2021/06/17 17:20:14 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include "basics/basics.h"

typedef struct s_texture {
	void	*img;
	char	*data;
	int		bits;
	int		len;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_graph {
	struct s_texture	wall;
	struct s_texture	coin;
	struct s_texture	back;
	struct s_texture	black;
	struct s_texture	door_c;
	struct s_texture	player;
}	t_graph;

typedef struct s_map {
	int				fd;
	int				collec;
	int				start;
	int				exit;
	int				width;
	int				height;
	int				pos_x;
	int				pos_y;
	int				chunk_x;
	int				chunk_y;
	int				count;
	int				done;
	void			*mlx;
	void			*win;
	char			**plan;
	struct s_graph	graph;
}	t_map;

int		ft_destroy(t_map *map);
void	print_error(int code);
void	split_error(char **split, int code);
void	ft_open(t_map *map, char *file);
void	ft_parse(t_map *mp);
//t_graph	create_map(t_map *map);
void	create_texture(t_graph *graph, t_map *game);
void	put_image(void *texture, int i, int j, t_map *map);
void	putcoin(void *texture, int i, int j, t_map *map);
void	write_image(t_map *map);

int		controls(int keycode, t_map *map);
void	coin(t_map *map, int y, int x);
void	door(t_map *map, int y, int x);

#endif
