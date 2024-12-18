#include "basics.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		size;
	int		i;
	int		j;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	size = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * size + 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
