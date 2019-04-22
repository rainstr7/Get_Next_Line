/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:36:19 by ihahn             #+#    #+#             */
/*   Updated: 2019/03/05 17:20:36 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int n;
	int i;
	int sign;

	n = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (ft_isspace(str[i]) || (str[i] >= 0 && str[i] < 32))
		return (0);
	while (str[i])
		if ((str[i] >= 48) && (str[i] <= 57))
			n = 10 * n + (str[i++] - 48);
		else
			break ;
	return (n * sign);
}
