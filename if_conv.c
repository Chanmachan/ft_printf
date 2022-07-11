#include "ft_printf.h"

int	if_d_or_i(va_list *args)
{
	int	rtn;
	int	conv;

	rtn = 0;
	conv = va_arg(*args, int);
	rtn += ft_putnbr(conv);
	return (rtn);
}

int	if_s(va_list *args, int count)
{
	int		rtn;
	char	*s;

	rtn = 0;
	s = va_arg(*args, char *);
	if (!s)
	{
		rtn += 6;
		ft_putstr("(null)", count);
		return (rtn);
	}
	rtn = ft_putstr(s, count);
	return (rtn);
}

int	if_c(va_list *args)
{
	int	rtn;
	int	conv;

	rtn = 0;
	conv = va_arg(*args, int);
	rtn += ft_putchar((char)conv);
	return (rtn);
}

int	if_x(va_list *args, char x_X)
{
	int				rtn;
	unsigned int	conv;

	rtn = 0;
	conv = va_arg(*args, unsigned int);
	rtn += (int)ft_put_conv_base(conv, x_X);
	return (rtn);
}

int	if_u(va_list *args)
{
	int				rtn;
	unsigned int	u;

	rtn = 0;
	u = va_arg(*args, unsigned int);
	rtn += ft_putnbr(u);
	return (rtn);
}

int	if_p(va_list *args, int count)
{
	int		rtn;
	void	*p;
	char	c;

	c = 'x';
	rtn = 0;
	p = va_arg(*args, void *);
	rtn += ft_putstr("0x", count);
	rtn += (int)ft_put_conv_base((unsigned long long)p, c);
	return (rtn);
}

int	check_conv(char *str, va_list *args, int count)
{
	int		rtn;
	size_t	i;

	rtn = 0;
	i = 1;
	if (str[i] == 'd' || str[i] == 'i')
		rtn += if_d_or_i(args);
	else if (str[i] == 's')
		rtn += if_s(args, count);
	else if (str[i] == 'c')
		rtn += if_c(args);
	else if (str[i] == 'x' || str[i] == 'X')
		rtn += if_x(args, str[i]);
	else if (str[i] == '%')
		rtn += ft_putchar('%');
	else if (str[i] == 'u')
		rtn += if_u(args);
	else if (str[i] == 'p')
		rtn += if_p(args, count);
	return (rtn);
}
