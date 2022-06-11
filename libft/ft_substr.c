#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char *new_s;
	char *rtn_str;
	unsigned int 	len_s;

	i = 0;
	new_s = (char *) s;
	len_s = (unsigned int)ft_strlen(s);
	if (len_s < start)
	{
		rtn_str = ft_strdup("\0");
		return (rtn_str);
	}
	if (!(rtn_str = (char *) malloc (sizeof(char) * (ft_strlen(s) - start + 1))))
		return (NULL);
	while (i < len && new_s[start] != '\0')
		rtn_str[i++] = new_s[start++];
	rtn_str[i] = '\0';
	return (rtn_str);
}

//L16 new_s[start] != '\0' important

/*
#include <stdio.h>

int main(void)
{
	char a[] = "BONJOUR LES HARICOTS !";
	unsigned int b = 8;
	size_t c = 14;

	printf("%s\n", ft_substr(a, b, c));
}
*/