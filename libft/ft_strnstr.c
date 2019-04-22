/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:33:44 by ihahn             #+#    #+#             */
/*   Updated: 2019/03/04 16:50:47 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t len)
{
	int		i;
	char	*begin;
	int		len_str;

	if (*src == '\0')
		return ((char *)dst);
	begin = (char *)src;
	len_str = 0;
	while (*dst && (len_str < (int)len))
	{
		i = 0;
		while (*dst == *src && (len_str < (int)len))
		{
			if (*(src + 1) == '\0')
				return ((char *)(dst - i));
			src++;
			len_str++;
			i++;
			dst++;
		}
		dst = dst - i + 1;
		src = begin;
		len_str = len_str - i + 1;
	}
	return (NULL);
}
