/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:32:05 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/21 16:41:16 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	merge_list(t_list **list_a, t_list **list_b)
{
	if (!list_a || !*list_a || !list_b || !*list_b)
		return ;
	while (*list_b)
	{
		if ((*list_a)->value <= (*list_b)->value)
			execute_movements(list_a, list_b, "ra");
		else
		{
			execute_movements(list_a, list_b, "pa");
			execute_movements(list_a, list_b, "ra");
		}
	}
}

void	merge_sort(t_list **list_a, t_list **list_b, int size)
{
	int		mid;
	int		i;

	i = 0;
	mid = size / 2;
	if (size <= 1 || !list_a || !*list_a)
		return ;
	if (size == 2)
	{
		if ((*list_a)->value > (*list_a)->next->value)
			execute_movements(list_a, list_b, "sa");
		return ;
	}
	while (i < mid)
	{
		execute_movements(list_a, list_b, "pb");
		i++;
	}
	merge_sort(list_a, list_b, size - mid);
	merge_sort(list_b, list_a, mid);
	merge_list(list_a, list_b);
}
