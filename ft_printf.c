/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:50:42 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/07/12 02:50:43 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_conv(char *str, va_list *args, int count)
{
	int		rtn;
	size_t	i;

	rtn = 0;
	i = 1;
	if (str[i] == 'd' || str[i] == 'i')
		rtn += if_d_or_i(args);
	else if (str[i] == 's')
		rtn += if_s(args, count);
	else if (str[i] == 'c')
		rtn += if_c(args);
	else if (str[i] == '%')
		rtn += ft_putchar('%');
	else if (str[i] == 'u')
		rtn += if_u(args);
	else if (str[i] == 'p' || str[i] == 'x' || str[i] == 'X')
		rtn += if_p_x(args, count, str[i]);
	return (rtn);
}

static int	read_args(char *str, va_list *args)
{
	int		rtn;
	int		count;
	size_t	i;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	rtn = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			rtn += check_conv(&str[i], args, count);
			if (rtn == -1)
				return (-1);
			i++;
		}
		else
			rtn += ft_putchar(str[i]);
		i++;
	}
	return (rtn);
}

int	ft_printf(const char *format, ...)
{
	int		rtn;
	va_list	args;

	va_start(args, format);
	rtn = read_args((char *)format, &args);
	va_end(args);
	return (rtn);
}

/*#include <string.h>

int main()
{
	int res;
	char *a = malloc(SIZE_MAX + 1);
	memset(a, 'n', SIZE_MAX);
	a[SIZE_MAX + 1] = '\0';
//	int d = INT_MAX;

	// ft_printf
	res = ft_printf("ft_printf :\t%s", a);
	printf("\n");
	printf("res :\t\t%d\n", res);
	// printf
	res = printf("printf    :\t%s", a);
	printf("\n");
	printf("res + 3 :\t%d\n", res);
}*/

/*#include <stdio.h>
#include <libc.h>

int main()
{
	int i = 0;
	char *s = (char *)calloc(1, (size_t)INT_MAX);
	memset(s, 'a', (size_t)INT_MAX);
	i = ft_printf("%s\n", s);
	printf("ft_printf : [%d]\n", i);
	return (0);
}*/

/*#include <stdio.h>
#include <limits.h>
#include <string.h>

int main(void)
{
	int	res;
	char str[] = "1234";
	unsigned int xX= 1234;
	char *a = malloc(sizeof(int) * (INT_MAX));
	memset(a, 'a', INT_MAX);

	res = ft_printf("%s\n", a);
	printf("res = [%d]\n", res);
	res = printf("%s\n", a);
	printf("res = [%d]\n", res);
	res = ft_printf("ft_printf :\t%X\n", xX);
	printf("res = [%d]\n", res);
	res = printf("printf :\t%X\n", xX);
	printf("res = [%d]\n", res);
	res = ft_printf("ft_printf :\t%p\n", str);
	printf("res = [%d]\n", res);
	res = printf("printf :\t%p\n", str);
	printf("res = [%d]\n", res);
}*/

/*#include <limits.h>

 int main(void)
{
	printf("ft_printf\n");
	ft_printf(" %p\n %p ", ULONG_MAX, -ULONG_MAX);
//	printf("\nprintf\n");
//	printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
}*/

/*#include <stdio.h>

int main(void)
{
	unsigned int i = 0;
//	long addi = (long)&i;
	char a[] = "";
	int res;

	res = 0;
	ft_printf("%c\n", 'c');
	ft_printf("%s\n", "abc");
	res = ft_printf("a = %p\n", a);
	printf("res = %d\n", res);
	printf("%c\n", 'c');
	printf("%s\n", "abc");
	res = printf("a = %p\n", a);
	printf("res = %d\n", res);
	printf("&i = %p\n", &i);
	printf("res = %d\n", res);
//	printf("&i = %ld\n", addi);


	return (0);
}*/

/*#ifdef TEST

#include <stdio.h>

#ifdef FT_PRINTF
#define F(...) res = ft_printf(__VA_ARGS__);
#else
#define F(...) res = printf(__VA_ARGS__);
#endif


int main(void)
{
	int	res;
	F("  d = [%d]\n", -123);
	F("res = %d\n", res);
	F("  i = [%i]\n", -2147483648);
	F("res = %d\n", res);
	F("  s = [%s]\n", "abc");
	F("res = %d\n", res);
	F("  c = [%c]\n", 'c');
	F("res = %d\n", res);
	F("  x = [%x]\n", -123);
	F("res = %d\n", res);
	F("  X = [%X]\n", -123);
	F("res = %d\n", res);
	F("percent = [%%]\n");
	F("res = %d\n", res);
	F("  u = [%u]\n", 4294967295);
	F("res = %d\n", res);
	return (0);
}
#endif*/
