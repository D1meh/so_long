/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:10:55 by mtaouil           #+#    #+#             */
/*   Updated: 2021/06/23 18:10:56 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"
# include "basics/basics.h"

typedef struct s_graphb {
	struct s_texture	wall;
	struct s_texture	coin;
	struct s_texture	coin2;
	struct s_texture	coin3;
	struct s_texture	coin4;
	struct s_texture	back;
	struct s_texture	black;
	struct s_texture	door_c;
	struct s_texture	door_o;
	struct s_texture	player;
	struct s_texture	player_r;
	struct s_texture	koopa;
	struct s_texture	koopa_r;
}	t_graphb;

typedef struct s_mapb {
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
	int				enemies;
	int				**enemy;
	void			*mlx;
	void			*win;
	char			**plan;
	struct s_graphb	graph;
}	t_mapb;

void		ft_openb(t_mapb *map, char *file);
void		ft_parseb(t_mapb *map);
char		*ft_itoa(long long int n);

void		create_textureb(t_graphb *graph, t_mapb *game);
void		putcoinb(int i, int j, t_mapb *map);
void		put_imageb(void *texture, int i, int j, t_mapb *map);
void		write_imageb(t_mapb *map);
void		enemies(t_mapb *map);
void		put_if(void *texture, int x, int y, t_mapb *map);

void		doorb(t_mapb *map, int y, int x);
void		coinb(t_mapb *map, int y, int x);
void		ft_putcount(t_mapb *map, int n);
void		enemy_contact(t_mapb *map);
int			controlsb(int keycode, t_mapb *map);
int			enemy_movement(t_mapb *map);
int			animation(t_mapb *map);
int			ft_destroyb(t_mapb *map);

#endif
