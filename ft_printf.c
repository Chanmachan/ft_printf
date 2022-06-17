#include "ft_printf.h"
#include <stdio.h>
#include "fukuma"
define fukuma

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

void 	ft_putnbr(long args)
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

int 	get_digit(long args)
{
	int 	digit;

	digit = 0;
	if (args == -2147483648)
		return (11);
	if (args < 0)
	{
		args *= -1;
		digit++;
	}
	while (args / 10 > 0)
	{
		args = args / 10;
		digit++;
	}
	digit++;
	return (digit);
}

int 	get_digit_hexa(int args)
{
	int  	digit;

	digit = 0;
	if (args < 0)
		args *= -1;
	while (args / 16)
	{
		args = args / 16;
		digit++;
	}
	digit++;
	return (digit);
}

int 	ft_put_conv_base_lower(unsigned int args)
{
	int 	rtn;
	char 	*str;
	int 	digit;

	if (args < 0)
	{
		args = args + 4294967295 + 1;
	}
	rtn = get_digit_hexa(args);
	digit = rtn;
	str = (char *) malloc (sizeof(char) * (digit + 1));
	if (str == NULL)
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

int 	ft_put_conv_base_upper(unsigned int args)
{
	int 	rtn;
	char 	*str;
	int 	digit;

	if (args < 0)
		args = args + 4294967295 + 1;
	rtn = get_digit_hexa(args);
	digit = rtn;
	str = (char *) malloc (sizeof(char) * (digit + 1));
	if (str == NULL)
		return (0);
	str[digit--] = '\0';
	if (args == 0)
		str[digit] = 48;
	while (args > 0)
	{
		if (args % 16 < 10)
			str[digit--] = (args % 16) + 48;
		else
			str[digit--] = (args % 16) + 55;
		args = args / 16;
	}
	ft_putstr_fd(str, 1);
	return (rtn);
}

int 	check_conv(char *str, va_list args)
{
	int 			rtn;
	int 			d;
	char			*s;
	int 			c;
	int 			x;
	int 			X;
	unsigned int	u;
	size_t 			i;

	rtn = 0;
	i = 1;
	if (str[i] == 'd' || str[i] == 'i')
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
	else if (str[i] == 'x') //have to fix when args is negative
	{
		x = va_arg(args, unsigned int);
		rtn += ft_put_conv_base_lower(x);
		return (rtn);
	}
	else if (str[i] == 'X') //have to fix when args is negative
	{
		X = va_arg(args, unsigned int);
		if (X < 0)
			X = X + 4294967295 + 1;
		rtn += ft_put_conv_base_upper(X);
		return (rtn);
	}
	else if (str[i] == '%')
	{
		rtn += ft_putchar_fd('%', 1);
		return (rtn);
	}
	else if (str[i] == 'u')
	{
		u = va_arg(args, unsigned int);
		ft_putnbr(u);
		rtn += get_digit(u);
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
	F("  d = [%d]\n", -123);
	F("res = %d\n", res);
	F("  i = [%i]\n", -2147483648);
	F("res = %d\n", res);
	F("  s = [%s]\n", "abc");
	F("res = %d\n", res);
	F("  c = [%c]\n", 'c');
	F("res = %d\n", res);
	F("  x = [%x]\n", -123);
	F("res = %d\n", res);
	F("  X = [%X]\n", -123);
	F("res = %d\n", res);
	F("percent = [%%]\n");
	F("res = %d\n", res);
	F("  u = [%u]\n", 4294967295);
	F("res = %d\n", res);
	F("  p = [%p]\n", 1);
	F("res = %d\n", res);
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
