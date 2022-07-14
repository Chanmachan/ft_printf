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

int	ft_putchar(char c, int count)
{
	if (INT_MAX - count < 1)
		return (-1);
	write(1, &c, 1);
	return (count + 1);
}

int	ft_putstr(char *s, int count)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	if (INT_MAX - (size_t)count <= len || len > (size_t)(INT_MAX))
	{
		return (-1);
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return ((int)i + count);
}

int	ft_putnbr(long args, int count)
{
	if (args < 0)
	{
		count = ft_putstr("-", count);
		args *= -1;
	}
	if (args >= 10)
	{
		count = ft_putnbr(args / 10, count);
		count = ft_putnbr(args % 10, count);
	}
	else
		count = ft_putchar((char)(args + 48), count);
	return (count);
}
