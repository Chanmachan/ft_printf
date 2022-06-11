#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	tmp[n + 1];

	i = 0;
	while (i < n)
	{
		tmp[i] = ((unsigned char *)src)[i];
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = tmp[i];
		i++;
	}
	return (dest);
}
