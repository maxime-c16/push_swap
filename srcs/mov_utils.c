/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:53:48 by mcauchy           #+#    #+#             */
/*   Updated: 2025/03/05 12:53:52 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	exec_swap(t_list **a, t_list **b, char c)
{
	if (c == 'a')
		swap(a);
	else if (c == 'b')
		swap(b);
	ft_printf("s%c\n", c);
}

static void	exec_push(t_list **a, t_list **b, char c)
{
	if (c == 'a')
		push(b, a);
	else if (c == 'b')
		push(a, b);
	ft_printf("p%c\n", c);
}

static void	exec_rotate(t_list **a, t_list **b, char c)
{
	if (c == 'a')
		rotate(a);
	else if (c == 'b')
		rotate(b);
	ft_printf("r%c\n", c);
}

static void	exec_revrotate(t_list **a, t_list **b, char c)
{
	if (c == 'a')
		reverse_rotate(a);
	else if (c == 'b')
		reverse_rotate(b);
	ft_printf("rr%c\n", c);
}

void	execute_movements(t_list **a, t_list **b, char *str)
{
	if (str[0] == 's')
		exec_swap(a, b, str[1]);
	else if (str[0] == 'p')
		exec_push(a, b, str[1]);
	else if (str[0] == 'r')
	{
		if (str[1] == 'r')
			exec_revrotate(a, b, str[2]);
		else
			exec_rotate(a, b, str[1]);
	}
}
