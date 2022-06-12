#include "ft_printf.h"
#include <stdio.h>

int 	ft_putchar_fd(char c, int fd)
{
	if (!c)
		return (0);
	write(fd, &c, 1);
	return (1);
}

int 	ft_putstr_fd(char *s, int fd)
{
	size_t 	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

void 	ft_putnbr(int args)
{
	if (args == -2147483648)
	{
		ft_putchar_fd('-', 1);
		ft_putchar_fd('2', 1);
		args = 147483648;
	}
	if (args < 0)
	{
		ft_putchar_fd('-', 1);
		args *= -1;
	}
	if (args >= 10)
	{
		ft_putnbr(args / 10);
		ft_putnbr(args % 10);
	}
	else
	{
		ft_putchar_fd(args + 48, 1);
	}
}

int 	get_digit(int args)
{
	int 	digit;

	digit = 0;
	while (args > 0)
	{
		args = args / 10;
		digit++;
	}
	return (digit);
}

int 	check_conv(char *str, va_list args)
{
	int 	rtn;
	int 	d;
	char	*s;
	size_t 	i;

	rtn = 0;
	i = 1;
	if (str[i] == 'd')
	{
		d = va_arg(args, int);
		ft_putnbr(d);
		rtn = get_digit(d);
		return (rtn);
	}
	else if (str[i] == 's')
	{
		s = va_arg(args, char *);
		rtn += ft_putstr_fd(s, 1);
		return (rtn);
	}
	else
		return (0);
}

int		ft_printf(const char *format, ...)
{
	char	*str;
	int 	rtn;
	va_list args;

	va_start(args, format);
	str = (char *) format;
	if (!str)
		return (0);
	rtn = 0;
	while (*str)
	{
		if (*str == '%')
		{
			rtn += check_conv(str, args);
			str = str + 2; //address move -> *%d*
		}
		rtn += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (rtn);
}

/*#ifdef TEST

#include <stdio.h>

#ifdef FT_PRINTF
#define F(...) res = ft_printf(__VA_ARGS__);
#else
#define F(...) res = printf(__VA_ARGS__);
#endif


int main(void)
{
	int	res;
	F("%d\n", 123);
	return (0);
}
#endif*/

#include <stdio.h>

int main(void)
{
	ft_printf("%s\n", "abc");
	printf("%s\n", "abc");
	return (0);
}
