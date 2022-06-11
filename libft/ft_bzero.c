#include "libft.h"

void	ft_bzero(void *s, int n)
{
	char uc;
	int i;

	uc = '\0';
	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = uc;
		i++;
	}
	return ;
}
