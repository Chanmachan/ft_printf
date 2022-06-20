#include "ft_printf.h"

int 	get_digit_hexa(unsigned long args)
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

unsigned int 	ft_put_conv_base_lower(unsigned long long args)
{
	unsigned int 	rtn;
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
	free(str);
	return (rtn);
}

int 	ft_put_conv_base_upper(unsigned long long args)
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
	free(str);
	return (rtn);
}