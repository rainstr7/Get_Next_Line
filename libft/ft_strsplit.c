/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 20:44:03 by ihahn             #+#    #+#             */
/*   Updated: 2019/03/07 17:49:36 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	if (!s || !(arr = (char **)malloc(sizeof(char*) * (ft_volarr(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
		{
			if ((arr[j++] = ft_writeword(i, s, c)) == NULL)
				return (ft_delarray(&arr, i));
		}
		else if (s[i] != c)
		{
			if (s[i - 1] == c)
				if ((arr[j++] = ft_writeword(i, s, c)) == NULL)
					return (ft_delarray(&arr, i));
		}
		i++;
	}
	arr[j] = NULL;
	return (arr);
}
