/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 20:32:23 by ihahn             #+#    #+#             */
/*   Updated: 2019/03/07 10:42:28 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	size;
	char			*str;
	char			*new_str;

	if (!s || start > (size = ft_strlen(s)) || start + len > size + 1)
		return (NULL);
	if (!(str = (char *)ft_memalloc(len * sizeof(char) + 1)))
		return (NULL);
	size = 0;
	new_str = str;
	while (*s)
	{
		if (size >= start && size < start + len)
		{
			*str = *s;
			str++;
		}
		s++;
		size++;
	}
	*str = '\0';
	return (new_str);
}
