/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:21:44 by ihahn             #+#    #+#             */
/*   Updated: 2019/03/04 11:40:56 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;

	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dst1 == src1 || len == 0)
		return (dst);
	while (len > 0)
	{
		if (dst1 < src1)
		{
			*dst1 = *src1;
			dst1++;
			src1++;
			len--;
		}
		else
		{
			dst1[len - 1] = src1[len - 1];
			len--;
		}
	}
	return (dst);
}
