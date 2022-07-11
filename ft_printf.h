#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int				ft_printf(const char *format, ...);
int 			ft_putchar_fd(char c, int fd);
int 			ft_putstr_fd(char *s, int fd);
int 			ft_putnbr(long args);
unsigned int 	ft_put_conv_base(unsigned long long args, char x_X);
int 			check_conv(char *str, va_list *args);
int 			if_d_or_i(va_list *args);
int 			if_s(va_list *args);
int 			if_c(va_list *args);
int				if_x(va_list *args, char x_X);
int 			if_u(va_list *args);
int 			if_p(va_list *args);

#endif