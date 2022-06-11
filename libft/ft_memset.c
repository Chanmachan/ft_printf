#include "libft.h"

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned char uc;
	unsigned int i;

	uc = c;
	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = uc;
		i++;
	}
	return (s);
}

// L10 brackets are important