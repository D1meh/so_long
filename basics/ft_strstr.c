#include "basics.h"

int	ft_strstr(char *s1, char *s2)
{
	int	i;
	int	j;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (s1[i + j + 1] == s2[j + 1] && s2[j + 1] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
