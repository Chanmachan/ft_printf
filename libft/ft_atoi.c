#include "libft.h"

int	ft_atoi(const char *str)
{
	int	new_s;
	int	sign;
	size_t	i;

	new_s = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r'||
			str[i] == '\f' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		new_s = (new_s * 10) + (str[i] - 48);
		i++;
	}
	return (new_s * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char a[] = "	 \n-42 3";

	printf("%d\n", atoi(a));
	printf("%d\n", ft_atoi(a));
}
*/