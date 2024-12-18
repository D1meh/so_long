#include "basics.h"

void	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && s[i] == s[i + 1])
		{
			free(s);
			write(2, "Error\nEmpty line in map descriptor\n", 35);
			exit(12);
		}
		i++;
	}
}
