#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
#include <stdio.h>

int main(void)
{
	int a = '5';
	printf("%d", ft_isdigit(a));
}
*/