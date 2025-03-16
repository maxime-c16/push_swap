/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:16:38 by mcauchy           #+#    #+#             */
/*   Updated: 2025/03/16 14:32:41 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_value(t_list **lst)
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

static int	get_max_bits(t_list *lst)
{
	int	max_bits;
	int	max;
	int	i;

	max_bits = 0;
	max = get_max_value(&lst);
	i = 0;
	while (max)
	{
		max >>= 1;
		max_bits++;
	}
	return (max_bits);
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

static void	sort_list(t_list **lst, t_list **b, int i)
{
	t_list	*tmp;
	int		size;

	tmp = *lst;
	size = ft_lstsize(tmp);
	while (size--)
	{
		if ((tmp->index >> i) & 1)
			execute_movements(lst, b, "ra");
		else
			execute_movements(lst, b, "pb");
		tmp = *lst;
	}
	while (*b)
		execute_movements(lst, b, "pa");
}

static int	is_sorted(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	radix_sort(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		max_bits;
	int		i;

	i = 0;
	tmp = *lst;
	tmp2 = NULL;
	normalize_list(lst);
	max_bits = get_max_bits(tmp);
	while (i <= max_bits && !is_sorted(lst))
	{
		sort_list(lst, &tmp2, i);
		i++;
	}
}
