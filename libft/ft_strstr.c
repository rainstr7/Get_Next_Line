/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:48:55 by ihahn             #+#    #+#             */
/*   Updated: 2019/02/17 20:23:22 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*temp;

	if (*needle == '\0')
		return ((char *)haystack);
	temp = (char *)needle;
	while (*haystack)
	{
		i = 0;
		while (*haystack == *needle)
		{
			if (*(needle + 1) == '\0')
				return ((char *)(haystack - i));
			i++;
			haystack++;
			needle++;
		}
		haystack = haystack - i + 1;
		needle = temp;
	}
	return (NULL);
}
