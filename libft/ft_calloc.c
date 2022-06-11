#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*rtn_box;
	if(n <= 4294967295 && size <= 42949667295)
	{
		rtn_box = (void *) malloc (n * size);
		if (rtn_box == NULL)
			return (NULL);
		ft_memset(rtn_box, 0, n * size);
		return (rtn_box);
	}
	return (NULL);
}

//L3 if n or size is max of size_t