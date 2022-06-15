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
	while (args / 10 > 0)
	{
		args = args / 10;
		digit++;
	}
	digit++;
	return (digit);
}

int 	get_digit_onesix(unsigned long args)
{
	int  	digit;

	digit = 0;
	while (args / 16)
	{
		args = args / 16;
		digit++;
	}
	digit++;
	return (digit);
}

int 	ft_put_conv_base(int args)
{
	int 	rtn;
	char 	*str;
	int 	digit;

	if (args == -2147483648)
	{
		ft_putstr_fd("80000000", 1);
		return (8);
	}
	rtn = get_digit_onesix(args);
	digit = rtn;
	if (!(str = (char *) malloc (sizeof(char) * (digit + 1))))
		return (0);
	str[digit--] = '\0';
	if (args == 0)
		str[digit] = 48;
	while (args > 0)
	{
		if (args % 16 < 10)
			str[digit--] = (args % 16) + 48;
		else
			str[digit--] = (args % 16) + 87;
		args = args / 16;
	}
	ft_putstr_fd(str, 1);
	return (rtn);
}

int 	check_conv(char *str, va_list args)
{
	int 	rtn;
	int 	d;
	char	*s;
	int 	c;
	int 	x;
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
//		printf("\ns_rtn = %d\n", rtn);
		return (rtn);
	}
	else if (str[i] == 'c')
	{
		c = va_arg(args, int);
		rtn += ft_putchar_fd((char)c, 1);
//		printf("\nc_rtn = %d\n", rtn);
		return (rtn);
	}
	else if (str[i] == 'x')
	{
		x = va_arg(args, int);
		rtn += ft_put_conv_base(x);
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
			continue;
		}
		rtn += ft_putchar_fd(*str, 1);
//		printf("\nlast_rtn = %d\n", rtn);
		str++;
	}
	va_end(args);
//	printf("last_rtn = %d\n", rtn);
	return (rtn);
}

#ifdef TEST

#include <stdio.h>

#ifdef FT_PRINTF
#define F(...) res = ft_printf(__VA_ARGS__);
#else
#define F(...) res = printf(__VA_ARGS__);
#endif


int main(void)
{
	int	res;
	F("[%x]\n", 123);
	F("res = [%d]\n", res);
	return (0);
}
#endif

#include <stdio.h>

/*int main(void)
{
	ft_printf("%c\n", 'c');
	ft_printf("%s\n", "abc");
	printf("%c\n", 'c');
	printf("%s\n", "abc");
	return (0);
}*/
