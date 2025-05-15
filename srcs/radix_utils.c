/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:38:16 by mcauchy           #+#    #+#             */
/*   Updated: 2025/05/15 12:40:48 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max_value(t_list **lst)
{
	t_list	*tmp;
	int		max;

	max = INT_MIN;
	tmp = *lst;
	if (tmp)
	{
		max = tmp->value;
		while (tmp)
		{
			if (tmp->value > max)
				max = tmp->value;
			tmp = tmp->next;
		}
		return (max);
	}
	return (0);
}

void	sort_three(void)
{
	int		max;

	max = get_max_value(_lst());
	if ((*_lst())->value == max)
		execute_movements(_lst(), NULL, "ra");
	else if ((*_lst())->next->value == max)
		execute_movements(_lst(), NULL, "rra");
	if ((*_lst())->value > (*_lst())->next->value)
		execute_movements(_lst(), NULL, "sa");
}

void	sort_small(int size)
{
	if (!is_sorted(_lst()) && size == 2)
		execute_movements(_lst(), NULL, "sa");
	else if (!is_sorted(_lst()) && size == 3)
		sort_three();
	else if (!is_sorted(_lst()) && size <= 5)
		sort_five();
	else
		return ;
}

static int	binary_search_index(int *tab, int size, int target)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (tab[mid] == target)
			return (mid);
		if (tab[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

void	normalize_list(t_list **lst)
{
	t_list	*tmp;
	int		*tab;
	int		size;
	int		i;

	i = 0;
	tmp = *lst;
	size = ft_lstsize(tmp);
	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return ;
	while (tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	ft_sort_int_tab(tab, size);
	tmp = *lst;
	while (tmp)
	{
		tmp->index = binary_search_index(tab, size, tmp->value);
		tmp = tmp->next;
	}
	free(tab);
}
