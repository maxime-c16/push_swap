/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:04:18 by mcauchy           #+#    #+#             */
/*   Updated: 2025/03/13 17:47:34 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_min_value(t_list **lst)
{
	t_list	*tmp;
	int		min;

	min = INT_MAX;
	tmp = *lst;
	if (tmp)
	{
		min = tmp->value;
		while (tmp)
		{
			if (tmp->value < min)
				min = tmp->value;
			tmp = tmp->next;
		}
		return (min);
	}
	return (0);
}

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

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

int	find_median(t_list *tmp)
{
	int		*tab;
	int		i;
	int		median;

	tab = (int *)malloc(sizeof(int) * ft_lstsize(tmp));
	if (!tab)
		return (0);
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	ft_sort_int_tab(tab, i);
	if (i % 2 == 0)
		median = tab[i / 2];
	else
		median = tab[i / 2 + 1];
	free(tab);
	return (median);
}

void	rotate_to_min(t_list **lst)
{
	t_list	*tmp;
	int		min;
	int		i;
	int		index;

	min = get_min_value(lst);
	// ft_printf("min: %d, tmpval %d\n", min, (*lst)->value);
	tmp = *lst;
	i = 0;
	index = 0;
	if (tmp->value == min)
		return ;
	while (tmp)
	{
		if (tmp->value <= min)
		{
			min = tmp->value;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	// ft_printf("index: %d, i: %d\n", index, i);
	if (index < i / 2)
	{
		while (index)
		{
			index--;
			execute_movements(lst, NULL, "ra");
		}
	}
	else
	{
		while (i - index)
		{
			index++;
			execute_movements(lst, NULL, "rra");
		}
	}
}

void	sort_three(t_list **lst)
{
	t_list	*tmp;
	int		first;
	int		second;
	int		third;

	tmp = *lst;
	first = tmp->value;
	second = tmp->next->value;
	third = tmp->next->next->value;
	if (first < second && second < third)
		return ;
	if (first > second && first < third)
		execute_movements(lst, NULL, "sa");
	else if (first > second && second > third)
	{
		execute_movements(lst, NULL, "sa");
		execute_movements(lst, NULL, "rra");
	}
	else if (first > second && first > third && second < third)
		execute_movements(lst, NULL, "ra");
	else if (first < second && first < third && second > third)
	{
		execute_movements(lst, NULL, "sa");
		execute_movements(lst, NULL, "ra");
	}
	else if (first < second && first > third)
		execute_movements(lst, NULL, "rra");
}

int	is_correct_pos(t_list **lst, int val)
{
	t_list	*tmp;
	int		min;
	int		max;

	tmp = *lst;
	min = get_min_value(lst);
	max = get_max_value(lst);
	if (val < min || val > max)
		return (1);
	if (tmp->value <= val && tmp->next->value >= val)
	{
		execute_movements(lst, NULL, "ra");
		return (1);
	}
	return (0);
}

void	insert_from_b(t_list **a, t_list **b)
{
	// ft_printf("inserting %d from b\n", (*b)->value);
	// print_list(*b);
	// ft_printf("Rotating a to min\n");
	rotate_to_min(a);
	// print_list(*b);
	while (!is_correct_pos(a, (*b)->value))
	{
		// ft_printf("Not in correct pos : %d, rotating a\n", (*b)->value);
		execute_movements(a, b, "ra");
		// print_list(*b);
	}
	// ft_printf("Correct pos found before %d\n", (*a)->value);
	// print_list(*b);
	execute_movements(a, b, "pa");
	// print_list(*b);
	// ft_printf("Rotating back to min\n");
	rotate_to_min(a);
}

void	turkish(t_list **a)
{
	int		median;
	t_list	*b;

	b = NULL;
	// print_list(b);
	// ft_printf("Performing turkish sort\n");
	// ft_printf("Step 1: Splitting list\n");
	while (ft_lstsize(*a) > 3)
	{
		median = find_median(*a);
		// ft_printf("median: %d\n", median);
		if ((*a)->value <= median)
			execute_movements(a, &b, "pb");
		else
			execute_movements(a, NULL, "ra");
	}
	// print_list(b);
	// ft_printf("Step 2: Sorting list a with 3 elem\n");
	sort_three(a);
	// print_list(b);
	// ft_printf("Step 3: Merging lists\n");
	while (b)
		insert_from_b(a, &b);
	// print_list(b);
	// ft_printf("Step 4: Rotating to min\n");
	rotate_to_min(a);
	// print_list(b);
}
