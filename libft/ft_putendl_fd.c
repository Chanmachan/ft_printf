//
// Created by 本間優之介 on 2022/06/07.
//
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
int main(void)
{
	ft_putendl_fd("123", 1);
}
 */