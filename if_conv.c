#include "ft_printf.h"

int 	if_d_or_i(va_list *args)
{
	int		rtn;
	int 	conv;

	rtn = 0;
	conv = va_arg(*args, int);
	rtn += ft_putnbr(conv);
	return (rtn);
}

int 	if_s(va_list *args)
{
	int 	rtn;
	char	*s;

	rtn = 0;
	s = va_arg(*args, char *);
	if (!s)
	{
		rtn += 6;
		ft_putstr_fd("(null)", 1);
		return (rtn);
	}
	rtn += ft_putstr_fd(s, 1);
	return (rtn);
}

int 	if_c(va_list *args)
{
	int		rtn;
	int 	conv;

	rtn = 0;
	conv = va_arg(*args, int);
	rtn += ft_putchar_fd(conv, 1);
	return (rtn);
}

int 	if_x(va_list *args)
{
	int 	rtn;
	unsigned int conv;

	rtn = 0;
	conv = va_arg(*args, unsigned int);
	rtn += ft_put_conv_base_lower(conv);
	return (rtn);
}

int 	if_X(va_list *args)
{
	int 	rtn;

	unsigned int conv;
	rtn = 0;
	conv = va_arg(*args, unsigned int);
	rtn += ft_put_conv_base_upper(conv);
	return (rtn);
}

int 	if_u(va_list *args)
{
	int 	rtn;

	unsigned int u;
	rtn = 0;
	u = va_arg(*args, unsigned int);
	rtn += ft_putnbr(u);
	return (rtn);
}

int 	if_p(va_list *args)
{
	int 	rtn;
	void	*p;

	rtn = 0;
	p = va_arg(*args, void *);
	rtn += ft_putstr_fd("0x", 1);
	rtn += ft_put_conv_base_lower((unsigned long long)p);
	return (rtn);
}

int 	check_conv(char *str, va_list *args)
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
