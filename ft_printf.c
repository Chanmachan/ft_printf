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

static long long	check_conv(char *str, va_list *args, long long count)
{
	size_t	i;

	i = 1;
	if (str[i] == 'd' || str[i] == 'i')
		count = if_d_or_i(args, count);
	if (str[i] == 's')
		count = if_s(args, count);
	if (str[i] == 'c')
		count = if_c(args, count);
	if (str[i] == '%')
		count = ft_putchar('%', count);
	if (str[i] == 'u')
		count = if_u(args, count);
	if (str[i] == 'p' || str[i] == 'x' || str[i] == 'X')
		count = if_p_x(args, count, str[i]);
	return (count);
}

static int	read_args(char *str, va_list *args)
{
	long long	rtn;
	size_t		i;

	i = 0;
	rtn = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			rtn = check_conv(&str[i], args, rtn);
			i++;
		}
		else
			rtn = ft_putchar(str[i], rtn);
		if (rtn == -1 || rtn > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)rtn);
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

/*#include <libc.h>
#include "ft_printf.h"

int main()
{
	int i = 0;
	char *s = (char *)calloc(1, (size_t)INT_MAX - 4);
	memset(s, 'a', (size_t)INT_MAX - 5);
	int d = INT_MAX;
	i = ft_printf("%s%d\n", s, d);
	printf("%d\n", i);
	i = printf("%s%d\n", s, d);
	printf("%d\n", i);
	free(s);
	return (0);
}*/

/*#include <libc.h>

int main()
{
	int res;
	long long d;
	d = 74803470839240738;
	res = ft_printf(" %u\n", d);
	printf("res : [%d]\n", res);
	res = printf(" %llu\n", d);
	printf("res : [%d]\n", res);
}*/

/*#include <stdio.h>
#include <limits.h>
#include <libc.h>

int main()
{
	int res;
	char *a = calloc(1, INT_MAX);
	memset(a, 'a', INT_MAX - 1);
	memset(a + INT_MAX - 1, 0, 1);
//	char *s = (char *)calloc(1, (size_t)INT_MAX + 10);
//	memset(s, 'a', (size_t)INT_MAX + 5);

	res = ft_printf(NULL);
	printf("\nres = [%d]\n", res);
	res = ft_printf("aaa%sd\n", a);
	printf("res = [%d]\n", res);
	res = printf("aaa%s\n", a);
	printf("res = [%d]\n", res);
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
