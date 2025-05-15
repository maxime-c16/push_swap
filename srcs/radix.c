/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:16:38 by mcauchy           #+#    #+#             */
/*   Updated: 2025/05/15 12:41:15 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	is_sorted(t_list **lst)
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
	if (ft_lstsize(tmp) <= 5)
	{
		sort_small(ft_lstsize(tmp));
		return ;
	}
	normalize_list(lst);
	max_bits = get_max_bits(tmp);
	while (i <= max_bits && !is_sorted(lst))
	{
		sort_list(lst, &tmp2, i);
		i++;
	}
}
