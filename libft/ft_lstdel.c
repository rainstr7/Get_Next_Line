/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 21:38:43 by ihahn             #+#    #+#             */
/*   Updated: 2019/03/07 10:27:40 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*nxtlist;

	list = *alst;
	while (list)
	{
		nxtlist = list->next;
		del(list->content, list->content_size);
		free(list);
		list = nxtlist;
	}
	*alst = NULL;
}
