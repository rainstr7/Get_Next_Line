/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 10:19:19 by ihahn             #+#    #+#             */
/*   Updated: 2019/03/07 17:56:11 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_writeword(int start, char const *str, char c)
{
	int		word;
	char	*temp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	word = start;
	while (str[word] != c && str[word])
	{
		word++;
		len++;
	}
	temp = (char*)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (start < word)
		temp[i++] = str[start++];
	temp[i] = '\0';
	return (temp);
}
