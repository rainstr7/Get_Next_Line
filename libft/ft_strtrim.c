/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 20:41:51 by ihahn             #+#    #+#             */
/*   Updated: 2019/03/04 14:41:11 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t			i;
	unsigned int	begin;
	unsigned int	end;

	i = 0;
	begin = 0;
	end = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	begin = i;
	while (s[i] != '\0')
	{
		if (s[i] >= 33 && s[i] <= 126)
			end = i;
		i++;
	}
	if (end == 0)
		return (ft_strnew(1));
	return (ft_strsub(s, begin, (size_t)(end - begin + 1)));
}
