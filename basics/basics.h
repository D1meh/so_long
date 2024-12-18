/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:20:20 by mtaouil           #+#    #+#             */
/*   Updated: 2021/06/17 17:20:22 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICS_H
# define BASICS_H

# include <stdlib.h>
# include <unistd.h>
# include "../so_long.h"

# define BUFFER_SIZE 32

char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(long long int n);
char	**ft_split(char const *s, char c);
void	free_split(char **tab);
void	ft_putstr(char *s);
void	ft_strchr(char *s);
void	ft_putnbr(int n);
int		split_len(char **split);
int		ft_strlen(char *s);
int		ft_only1(char *s);
int		ft_strstr(char *s1, char *s2);

#endif
