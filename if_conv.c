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

int	if_u(va_list *args)
{
	int				rtn;
	unsigned int	u;

	rtn = 0;
	u = va_arg(*args, unsigned int);
	rtn += ft_putnbr(u);
	return (rtn);
}

int	if_p_x(va_list *args, int count, char c)
{
	int				rtn;
	void			*p;
	unsigned int	conv;

	rtn = 0;
	if (c == 'p')
	{
		p = va_arg(*args, void *);
		rtn += ft_putstr("0x", count);
		rtn += (int) ft_put_conv_base((unsigned long long) p, c);
	}
	else
	{
		conv = va_arg(*args, unsigned int);
		rtn += (int) ft_put_conv_base(conv, c);
	}
	return (rtn);
}
