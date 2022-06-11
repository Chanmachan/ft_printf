//
// Created by 本間優之介 on 2022/06/07.
//
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*itoa_str;

	itoa_str = ft_itoa(n);
	ft_putstr_fd(itoa_str, fd);
	free (itoa_str);
}

//free needed

/*
int main(void)
{
	ft_putnbr_fd(2147483647, 1);
}
 */