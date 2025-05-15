/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:12:38 by macauchy          #+#    #+#             */
/*   Updated: 2025/05/15 12:42:42 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_index(t_list **lst, int value)
{
	t_list	*tmp;
	int		index;

	tmp = *lst;
	index = 0;
	while (tmp)
	{
		if (tmp->value == value)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

static void	push_back_b(t_list **a, t_list **b, int min)
{
	int		size;
	int		pos;

	pos = find_index(a, min);
	size = ft_lstsize(*a);
	if (pos < size / 2)
	{
		while ((*a)->value != min)
			execute_movements(a, b, "ra");
	}
	else
	{
		while ((*a)->value != min)
			execute_movements(a, b, "rra");
	}
	execute_movements(a, b, "pb");
}

static int	find_min(void)
{
	t_list	*lst;
	int		min;

	lst = *_lst();
	min = INT_MAX;
	while (lst)
	{
		if (lst->value < min)
			min = lst->value;
		lst = lst->next;
	}
	return (min);
}

void	sort_five(void)
{
	int		min;
	int		next_min;
	t_list	**lst;
	t_list	*b;

	lst = _lst();
	b = NULL;
	min = find_min();
	push_back_b(_lst(), &b, min);
	next_min = find_min();
	push_back_b(_lst(), &b, next_min);
	sort_three();
	execute_movements(_lst(), &b, "pa");
	execute_movements(_lst(), &b, "pa");
	if (lst && *lst && (*lst)->next)
	{
		if ((*lst)->value > (*lst)->next->value)
			execute_movements(_lst(), &b, "sa");
	}
}
