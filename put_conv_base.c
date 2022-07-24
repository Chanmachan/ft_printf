/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_conv_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:50:48 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/07/12 02:50:49 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_digit_hexa(unsigned long args)
{
	int	digit;

	digit = 0;
	while (args / 16)
	{
		args = args / 16;
		digit++;
	}
	digit++;
	return (digit);
}

static char	*put_conv(char *str, unsigned long long args, size_t digit)
{
	str[digit--] = '\0';
	if (args == 0)
		str[digit] = 48;
	while (args > 0)
	{
		if (args % 16 < 10)
			str[digit--] = (char)((args % 16) + 48);
		else
			str[digit--] = (char)((args % 16) + 87);
		args = args / 16;
	}
	return (str);
}

long long	ft_put_conv_base(unsigned long long args, char x_X, long long count)
{
	unsigned int	rtn;
	char			*str;
	size_t			digit;
	size_t			i;

	rtn = get_digit_hexa(args);
	digit = rtn;
	str = (char *) malloc (sizeof(char) * (digit + 1));
	if (str == NULL)
		return (0);
	str = put_conv(str, args, digit);
	i = 0;
	if (x_X == 'X')
	{
		while (str[i] != '\0')
		{
			str[i] = (char)ft_toupper(str[i]);
			i++;
		}
	}
	ft_putstr(str, count);
	free(str);
	return (rtn + count);
}
