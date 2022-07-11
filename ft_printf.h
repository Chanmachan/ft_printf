#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

# include <stdio.h>

int				ft_printf(const char *format, ...);
int				read_args(char *str, va_list *args);
int 			ft_putchar(char c);
int 			ft_putstr(char *s, int count);
int 			ft_putnbr(long args);
unsigned int 	ft_put_conv_base(unsigned long long args, char x_X);
int 			check_conv(char *str, va_list *args, int count);
int 			if_d_or_i(va_list *args);
int 			if_s(va_list *args, int count);
int 			if_c(va_list *args);
int				if_x(va_list *args, char x_X);
int 			if_u(va_list *args);
int 			if_p(va_list *args, int count);;

#endif