/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:50:32 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/07/12 02:50:33 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_d_or_i(va_list *args, int count)
{
	int	conv;

	conv = va_arg(*args, int);
	count = ft_putnbr(conv, count);
	return (count);
}

int	if_s(va_list *args, int count)
{
	char	*s;

	s = va_arg(*args, char *);
	if (!s)
	{
		count = ft_putstr("(null)", count);
		return (count);
	}
	count = ft_putstr(s, count);
	return (count);
}

int	if_c(va_list *args, int count)
{
	int	rtn;
	int	conv;

	rtn = 0;
	conv = va_arg(*args, int);
	rtn += ft_putchar((char)conv, count);
	return (rtn);
}

int	if_u(va_list *args, int count)
{
	int				rtn;
	unsigned int	u;

	rtn = 0;
	u = va_arg(*args, unsigned int);
	rtn += ft_putnbr(u, count);
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
		rtn += (int) ft_put_conv_base((unsigned long long) p, c, count);
	}
	else
	{
		conv = va_arg(*args, unsigned int);
		rtn += (int) ft_put_conv_base(conv, c, count);
	}
	return (rtn);
}
