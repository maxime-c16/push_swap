/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:57:27 by maximecauch       #+#    #+#             */
/*   Updated: 2025/02/16 11:29:54 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*tmp;
	t_list	*new;

	tmp = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->value));
		if (!new)
		{
			while (tmp)
			{
				new = tmp->next;
				(*del)(tmp->value);
				free(tmp);
				tmp = new;
			}
			return (NULL);
		}
		ft_lstadd_back(&tmp, new);
		lst = lst->next;
	}
	return (tmp);
}
