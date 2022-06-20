#include "ft_printf.h"

int 	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int 	ft_putstr_fd(char *s, int fd)
{
	size_t 	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int 	ft_putnbr(long args)
{
	int 	rtn;

	rtn = 0;
	if (args == -2147483648)
	{
		rtn += ft_putchar_fd('-', 1);
		rtn += ft_putchar_fd('2', 1);
		args = 147483648;
	}
	if (args < 0)
	{
		rtn += ft_putchar_fd('-', 1);
		args *= -1;
	}
	if (args >= 10)
	{
		rtn += ft_putnbr(args / 10);
		rtn += ft_putnbr(args % 10);
	}
	else
		rtn += ft_putchar_fd(args + 48, 1);
	return (rtn);
}