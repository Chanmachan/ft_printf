/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:13:37 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/07/08 01:13:38 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	uc;
	size_t			i;

	uc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = uc;
		i++;
	}
	return (s);
}

// L10 brackets are important