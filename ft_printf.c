#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	char	*str;
	int 	rtn;
	va_list args;

	va_start(args, format);
	str = (char *) format;
	if (!str)
		return (0);
	rtn = 0;
	while (*str)
	{
		if (*str == '%')
		{
			rtn += check_conv(str, args);
			str = str + 2; //address move -> *%d*
			continue;
		}
		rtn += ft_putchar_fd(*str, 1);
//		printf("\nlast_rtn = %d\n", rtn);
		str++;
	}
	va_end(args);
	return (rtn);
}

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
