#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_printf(const char *format, ...);
int 	ft_putchar_fd(char c, int fd);
int 	ft_putstr_fd(char *s, int fd);
int 	ft_putnbr(long args);
int 	get_digit_hexa(unsigned long args);
unsigned int 	ft_put_conv_base_lower(unsigned long long args);
int 	ft_put_conv_base_upper(unsigned long long args);
int 	check_conv(char *str, va_list *args);
int 	if_d_or_i(va_list *args);
int 	if_s(va_list *args);
int 	if_c(va_list *args);
int 	if_x(va_list *args);
int 	if_X(va_list *args);
int 	if_u(va_list *args);
int 	if_p(va_list *args);

#endif