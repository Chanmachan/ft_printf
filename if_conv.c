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

long long	if_d_or_i(va_list *args, long long count)
{
	int	conv;

	conv = va_arg(*args, int);
	count = ft_putnbr(conv, count);
	return (count);
}

long long	if_s(va_list *args, long long count)
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

long long	if_c(va_list *args, long long count)
{
	int	conv;

	conv = va_arg(*args, int);
	count = ft_putchar((char)conv, count);
	return (count);
}

long long	if_u(va_list *args, long long count)
{
	unsigned int	u;

	u = va_arg(*args, unsigned int);
	count = ft_putnbr(u, count);
	return (count);
}

long long	if_p_x(va_list *args, long long count, char c)
{
	void			*p;
	unsigned int	conv;

	if (c == 'p')
	{
		p = va_arg(*args, void *);
		count = ft_putstr("0x", count);
		count = (int) ft_put_conv_base((unsigned long long) p, c, count);
	}
	else
	{
		conv = va_arg(*args, unsigned int);
		count = ft_put_conv_base(conv, c, count);
	}
	return (count);
}
