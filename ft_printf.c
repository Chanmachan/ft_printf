#include "ft_printf.h"

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

int	ft_printf(const char *format, ...)
{

	ft_putstr_fd((char *) format, 1);
	return (0);
}

#ifdef TEST

#include <stdio.h>

#ifdef FT_PRINTF
#define F(...) res = ft_printf(__VA_ARGS__);
#else
#define F(...) res = printf(__VA_ARGS__);
#endif


int main(void)
{
	int	res;
	F("123\n");
	return (0);
}
#endif

#include <stdio.h>

/*int main(void)
{
	ft_printf("hoge\n");
	printf("hoge\n");
	return (0);
}*/
