//
// Created by 本間優之介 on 2022/06/07.
//
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int main(void)
{
	ft_putchar_fd('2', 1);
}
 */