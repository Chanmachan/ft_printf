#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (n == 0)
	{
		return (len_src);
	}
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len_src);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[10] = "abcdefg";
	char b[] = "JJJJJJJJK";

	printf("%zu\n", ft_strlcpy(a, b, 8));
	printf("%s\n", a);

	char c[10] = "abcdefg";
	char d[] = "JJJJJJJJK";

	printf("%zu\n", strlcpy(c, d, 8));
	printf("%s\n", c);
}
*/