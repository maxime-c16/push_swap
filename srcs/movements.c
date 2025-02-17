/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:51:18 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/17 12:53:39 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

	if (!*lst)
		return ;
	head = *lst;
	second = head->next;
	third = second->next;
	second->next = head;
	head->next = third;
	*lst = second;
}

void	push(t_list **lst_from, t_list **lst_to)
{
	t_list	*tmp;
	t_list	*head;

	if (!*lst_from)
		return ;
	head = *lst_from;
	tmp = head->next;
	ft_lstadd_front(lst_to, head);
	*lst_from = tmp;
}

void	rotate(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;

	if  (!*lst)
		return ;
	head = *lst;
	tmp = head->next;
	head->next = NULL;
	*lst = tmp;
	ft_lstadd_back(lst, head);
}
void	reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*before_last;

	if (!*lst)
		return ;
	before_last = beforelast(*lst);
	tmp = before_last->next;
	before_last->next = NULL;
	ft_lstadd_front(lst, tmp);
}
