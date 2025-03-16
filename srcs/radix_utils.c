/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:38:16 by mcauchy           #+#    #+#             */
/*   Updated: 2025/03/16 14:40:57 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
