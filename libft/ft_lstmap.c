/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 21:43:40 by ihahn             #+#    #+#             */
/*   Updated: 2019/03/07 20:11:25 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

static t_list	*ft_del_re(t_list **list, void (*f)(void *, size_t))
{
	ft_lstdel(list, f);
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*list_new;
	t_list		*head;

	if (!lst || !f)
		return (NULL);
	list = (*f)(lst);
	if (!(head = ft_lstnew(list->content, list->content_size)))
		return (ft_del_re(&list_new, &ft_del));
	lst = lst->next;
	list_new = head;
	while (lst)
	{
		list = (*f)(lst);
		if (!(list_new->next = ft_lstnew(list->content, list->content_size)))
			return (ft_del_re(&list_new, &ft_del));
		list_new = list_new->next;
		lst = lst->next;
	}
	return (head);
}
