/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:51:18 by mcauchy           #+#    #+#             */
/*   Updated: 2025/05/12 14:45:23 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*beforelast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	swap(t_list **lst)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;

	if (!lst || !*lst)
		return ;
	head = *lst;
	second = head->next;
	third = second->next;
	second->next = head;
	head->next = third;
	*lst = second;
}

void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	rotate(t_list **lst)
{
	t_list	*stock;
	t_list	*head;

	if (ft_lstsize(*lst) < 2)
		return ;
	head = *lst;
	stock = ft_lstlast(head);
	*lst = head->next;
	head->next = NULL;
	stock->next = head;
}

void	reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*before_last;

	if (!lst || !*lst)
		return ;
	before_last = beforelast(*lst);
	tmp = before_last->next;
	before_last->next = NULL;
	ft_lstadd_front(lst, tmp);
}
