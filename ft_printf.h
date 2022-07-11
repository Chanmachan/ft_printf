/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:50:39 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/07/12 02:50:40 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

int				ft_printf(const char *format, ...);
int				ft_putchar(char c);
int				ft_putstr(char *s, int count);
int				ft_putnbr(long args);
unsigned int	ft_put_conv_base(unsigned long long args, char x_X);
int				if_d_or_i(va_list *args);
int				if_s(va_list *args, int count);
int				if_c(va_list *args);
int				if_u(va_list *args);
int				if_p_x(va_list *args, int count, char c);

#endif