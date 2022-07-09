#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char	*str;
	int 	rtn;
	va_list args;
	size_t 	i;

	i = 0;
	va_start(args, format);
	str = (char *) format;
	if (format == NULL || format[0] == '\0')
		return (-1);
	rtn = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			rtn += check_conv(&str[i], &args);
			i++;
		}
		else
			rtn += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (rtn);
}

/*#include <stdio.h>
#include <libc.h>

int main()
{
	int i = 0;
	char *s = (char *)calloc(1, (size_t)INT_MAX);
	memset(s, 'a', (size_t)INT_MAX);
	i = ft_printf("%s\n", s);
	printf("%d\n", i);
	return (0);
}*/

#include <stdio.h>

int main(void)
{
	int	res;
	char str[] = "1234";

	res = ft_printf("%p\n", str);
	printf("res = [%d]\n", res);
}

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
