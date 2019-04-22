/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:26:31 by ihahn             #+#    #+#             */
/*   Updated: 2019/03/07 10:28:05 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*str;

	str = NULL;
	if (size)
	{
		str = (char *)malloc(sizeof(char) * size);
		if (str)
			ft_bzero(str, size);
		else
			return (NULL);
	}
	return ((void *)str);
}
