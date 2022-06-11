#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size < len_dst)
		return (size + len_src);
	if (size > len_dst)
	{
		while (dst[i] != '\0')
			i++;
		dst = dst + i;
		i = 0;
		while (i < size - len_dst - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_dst + len_src);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[20] = "abc";
	char b[] = "jklmnopqr";

	// printf("%zu\n", ft_strlcat(a, b, sizeof(a)/sizeof(char)));
	printf("%zu\n", ft_strlcat(a, b, 8));
	printf("%s\n", a);

	char c[20] = "abc";
	char d[] = "jklmnopqr";

	printf("%lu\n", strlcat(c, d, 8));
	printf("%s\n", c);
}
*/