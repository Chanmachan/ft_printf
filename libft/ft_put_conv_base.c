//
// Created by 本間優之介 on 2022/06/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int 	ft_putchar_fd(char c, int fd)
{
	if (!c)
		return (0);
	write(fd, &c, 1);
	return (1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', 1);
		ft_putchar_fd('2', 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar_fd(nb + 48, 1);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t 	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

size_t 	get_digit(int num, size_t digit)
{
	while (num >= 10)
	{
		num = num / 10;
		digit++;
	}
	return (digit);
}

int 	convert_sign_plus(int num)
{
	if (num < 0)
	{
		num = num * -1;
	}
	return (num);
}

int	if_int_minimum(int num, char *chr_n, size_t *chanma)
{
	if (num == -2147483648)
	{
		chr_n[0] = '-';
		chr_n[1] = '2';
		num = 147483648;
		*chanma = 2;
	}
	return (num);
}

int if_negative(int num, char *chr_n, size_t *chanma)
{
	if (num < 0)
	{
		chr_n[0] = '-';
		num = num * -1;
		*chanma = 1;
	}
	return (num);
}

char	*put_char_num(int num, char *chr_n, size_t *chanma, size_t len)
{
	while (len-- > *chanma)
	{
		chr_n[len] = num % 10 + 48;
		num = num / 10;
	}
	return (chr_n);
}

char	*ft_itoa(int n)
{
	char	*chr_n;
	size_t 	len_n;
	int 	tmp_n;
	size_t 	chanma;

	tmp_n = n;
	len_n = 2;
	chanma = 0;
	if (tmp_n == -2147483648)
		len_n = 11;
	if (tmp_n < 0)
		len_n = len_n + 1;
	if (tmp_n < 0)
		tmp_n = convert_sign_plus(tmp_n);
	len_n = get_digit(tmp_n, len_n);
	if (!(chr_n = (char *)malloc(sizeof(char) * (len_n + 1))))
		return (NULL);
	n = if_int_minimum(n, chr_n, &chanma);
	n = if_negative(n, chr_n, &chanma);
	chr_n[len_n--] = '\0';
	chr_n = put_char_num(n, chr_n, &chanma, len_n);
	return (chr_n);
}

int 	get_digit_onesix(unsigned long args)
{
	int  	digit;

	digit = 0;
	while (args / 16)
	{
		args = args / 16;
		digit++;
	}
	digit++;
	printf("digit = %d\n", digit);
	return (digit);
}

int 	ft_put_conv_base(unsigned long args)
{
	unsigned long 	rtn;
	char 			*str;
	int 			digit;
	size_t 			i;

	rtn = get_digit_onesix(args);
	digit = rtn + 1;
	if (!(str = (char *) malloc (sizeof(char) * (digit + 1))))
		return (0);
	i = 0;
	while (args > 0)
	{
		printf("test00\n");
		if (args % 16 < 10)
		{
			printf("**[%lu]\n", args % 16 + 48);
			str[i] = (args % 16) + 48;
			printf("str[%zu] = %c\n", i, str[i]);
		}
		else
		{
			printf("##[%lu]\n", args % 16 + 87);
			str[i] = (args % 16) + 87;
			printf("str[%zu] = %c\n", i, str[i]);
		}
		i++;
		args = args / 16;
		digit--;
	}
	str[digit] = '\0';
	printf("\nstr[0] = ");
	ft_putchar_fd(str[0], 1);
	printf("\nstr[1] = ");
	ft_putchar_fd(str[1], 1);
	printf("\nstr[2] = ");
	ft_putchar_fd(str[2], 1);
	printf("\nstr[3] = ");
	ft_putchar_fd(str[3], 1);
//	printf("\nstr = ");
//	ft_putstr_fd(str, 1);
	printf("\n%s\n", str);
	return (rtn);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		unsigned long a = atoi(argv[1]);
		ft_put_conv_base(a);
//		printf("[%d]\n", );
	}
	else
		return (0);
}