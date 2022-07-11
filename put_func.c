/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:50:53 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/07/12 02:50:54 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s, int count)
{
	size_t	i;
	size_t	len;

	if (s[0] == '\0')
	{
		return (0);
	}
	len = ft_strlen(s);
	if (INT_MAX - len < len)
	{
		count = -1;
		return (count);
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return ((int)i);
}

int	ft_putnbr(long args)
{
	int	rtn;

	rtn = 0;
	if (args == -2147483648)
	{
		rtn += ft_putchar('-');
		rtn += ft_putchar('2');
		args = 147483648;
	}
	if (args < 0)
	{
		rtn += ft_putchar('-');
		args *= -1;
	}
	if (args >= 10)
	{
		rtn += ft_putnbr(args / 10);
		rtn += ft_putnbr(args % 10);
	}
	else
		rtn += ft_putchar(args + 48);
	return (rtn);
}
