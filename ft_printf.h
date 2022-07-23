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
# include "libft/libft.h"

int				ft_printf(const char *format, ...);
long long		ft_putchar(char c, long long count);
long long		ft_putstr(char *s, long long count);
long long		ft_putnbr(long args, long long count);
long long		ft_put_conv_base(unsigned long long args, \
									char x_X, long long count);
long long		if_d_or_i(va_list *args, long long count);
long long		if_s(va_list *args, long long count);
long long		if_c(va_list *args, long long count);
long long		if_u(va_list *args, long long count);
long long		if_p_x(va_list *args, long long count, char c);

#endif