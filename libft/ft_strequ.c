/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 20:20:42 by ihahn             #+#    #+#             */
/*   Updated: 2019/02/17 13:55:29 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	int	len1;
	int	len2;
	int	i;

	len1 = 0;
	len2 = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	else
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (len1 == len2)
		{
			while (i < len1 && s1[i] && s2[i])
			{
				if (s1[i] != s2[i])
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (0);
}
