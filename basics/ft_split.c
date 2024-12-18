/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:52:18 by mtaouil           #+#    #+#             */
/*   Updated: 2021/03/26 08:23:23 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basics.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	word_length(char const *s, char c, int a)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (s[i] == c)
		i++;
	while (a)
	{
		if (s[i] == c && s[i + 1] != c)
			a--;
		i++;
	}
	while (s[i] && s[i] != c)
	{
		length++;
		i++;
	}
	return (length);
}

static char	*cpyword(char const *s, char c, int a)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	j = 0;
	word = (char *)malloc(sizeof(char) * word_length(s, c, a) + 1);
	if (!word)
		return (NULL);
	while (s[i] == c)
		i++;
	while (a)
	{
		if (s[i] == c && s[i + 1] != c)
			a--;
		i++;
	}
	while (s[i] && s[i] != c)
	{
		word[j] = s[i];
		j++;
		i++;
	}
	word[j] = 0;
	return (word);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		cases;
	char	**tab;

	if (!s)
		return (NULL);
	cases = word_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (cases + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < cases)
	{
		tab[i] = cpyword(s, c, i);
		if (!tab[i])
		{
			free_split(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = 0;
	return (tab);
}
