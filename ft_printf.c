#include "ft_printf.h"
#include <stdio.h>

int 	ft_putchar_fd(char c, int fd)
{
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

int 	get_digit_hexa(long args)
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

int 	ft_put_conv_base_lower(long args)
{
	int 	rtn;
	char 	*str;
	int 	digit;

	if (args < 0)
		args = args + 4294967295 + 1; //unsigned int max + 1
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

int 	ft_put_conv_base_upper(long args)
{
	int 	rtn;
	char 	*str;
	int 	digit;

	if (args < 0)
		args = args + 4294967295 + 1;//unsigned int max + 1
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

int 	if_d_or_i(va_list args)
{
	int		rtn;
	int 	conv;

	rtn = 0;
	conv = va_arg(args, int);
	rtn += ft_putnbr(conv);
	return (rtn);
}

int 	if_s(va_list args)
{
	int 	rtn;
	char	*s;

	rtn = 0;
	s = va_arg(args, char *);
	rtn += ft_putstr_fd(s, 1);
	return (rtn);
}

int 	if_c(va_list args)
{
	int		rtn;
	int 	conv;

	rtn = 0;
	conv = va_arg(args, int);
	rtn += ft_putchar_fd((char)conv, 1);
	return (rtn);
}

int 	if_x(va_list args)
{
	int 	rtn;
	unsigned int conv;

	rtn = 0;
	conv = va_arg(args, unsigned int);
	rtn += ft_put_conv_base_lower(conv);
	return (rtn);
}

int 	if_X(va_list args)
{
	int 	rtn;

	unsigned int conv;
	rtn = 0;
	conv = va_arg(args, unsigned int);
	rtn += ft_put_conv_base_upper(conv);
	return (rtn);
}

int 	if_u(va_list args)
{
	int 	rtn;

	unsigned int u;
	rtn = 0;
	u = va_arg(args, unsigned int);
	rtn += ft_putnbr(u);
	return (rtn);
}

int 	if_p(va_list args)
{
	int 	rtn;
	void	*p;

	rtn = 0;
	p = va_arg(args, void *);
	rtn += ft_putstr_fd("0x", 1);
	rtn += ft_put_conv_base_lower((long)p);
	return (rtn);
}

int 	check_conv(char *str, va_list args)
{
	int 			rtn;
	size_t 			i;

	rtn = 0;
	i = 1;
	if (str[i] == 'd' || str[i] == 'i')
		rtn += if_d_or_i(args);
	else if (str[i] == 's')
		rtn += if_s(args);
	else if (str[i] == 'c')
		rtn += if_c(args);
	else if (str[i] == 'x')
		rtn += if_x(args);
	else if (str[i] == 'X')
		rtn += if_X(args);
	else if (str[i] == '%')
		rtn += ft_putchar_fd('%', 1);
	else if (str[i] == 'u')
		rtn += if_u(args);
	else if (str[i] == 'p')
		rtn += if_p(args);
	return (rtn);
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
	return (0);
}
#endif*/

#include <stdio.h>

int main(void)
{
	unsigned int i = 0;
//	long addi = (long)&i;
	char a[] = "";
	int res;

	ft_printf("%c\n", 'c');
	ft_printf("%s\n", "abc");
	res = ft_printf("a = %p\n", a);
	printf("res = %d\n", res);
	printf("%c\n", 'c');
	printf("%s\n", "abc");
	res = printf("a = %p\n", a);
	printf("res = %d\n", res);
	printf("&i = %p\n", &i);
	printf("res = %d\n", res);
//	printf("&i = %ld\n", addi);


	return (0);
}
