/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:38:16 by mcauchy           #+#    #+#             */
/*   Updated: 2025/05/12 16:17:00 by macauchy         ###   ########.fr       */
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

void	sort_three(t_list **l)
{
	int		max;
	t_list	*lst;

	lst = *l;
	max = get_max_value(&lst);
	if (lst->value == max)
		execute_movements(&lst, NULL, "ra");
	else if (lst->next->value == max)
		execute_movements(&lst, NULL, "rra");
	if (lst->value > lst->next->value)
		execute_movements(&lst, NULL, "sa");
}

void	sort_small(int size, t_list **b)
{
	if (!is_sorted(_lst()) && size == 2)
		execute_movements(_lst(), b, "sa");
	else if (!is_sorted(_lst()) && size == 3)
		sort_three(_lst());
	else if (!is_sorted(_lst()) && size <= 5)
		sort_five(b);
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
