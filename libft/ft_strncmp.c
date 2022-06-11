#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	new_s1 = (unsigned char *) s1;
	new_s2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (new_s1[i - 1] - new_s2[i - 1]);
	return (new_s1[i] - new_s2[i]);
}

/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_strncmp("1234", "1235", 3));
	printf("%d\n", strncmp("1234", "1235", 3));
}
*/