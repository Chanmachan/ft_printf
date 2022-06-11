#include "libft.h"

size_t 	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

size_t 	chanma(char *s1, char *s2)
{
	size_t 	chanma;
	size_t 	i;

	chanma = 0;
	i = 0;
	while (s1[i++] != '\0')
	{
		if (is_set(s1[i], s2) == 1)
			chanma++;
	}
	return (chanma);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rtn_str;
	size_t	i;
	size_t	j;

	if (!(rtn_str = (char *) malloc (sizeof(char) * (ft_strlen(s1) - chanma((char *)s1, (char *)set) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (((char *) s1)[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == 0)
			rtn_str[j++] = s1[i++];
		else
			i++;
	}
	rtn_str[j] = '\0';
	return (rtn_str);
}


/*
#include <stdio.h>

int main(void)
{
	char a[] = "   xxxtripouille   xxx";
	char b[] = " x";

	printf("%s\n", ft_strtrim(a, b));
}
*/
