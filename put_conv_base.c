#include "ft_printf.h"

#include <stdio.h>

static size_t	get_digit_hexa(unsigned long args)
{
	int	digit;

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

static char	*put_conv(char *str, unsigned long long args, size_t digit)
{
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
	return (str);
}

unsigned int	ft_put_conv_base(unsigned long long args, char x_X)
{
	unsigned int	rtn;
	char			*str;
	size_t			digit;
	size_t			i;

	if (args < 0)
		args = args + 4294967295 + 1;
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
	ft_putstr_fd(str, 1);
	free(str);
	return (rtn);
}
