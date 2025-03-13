/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:12:12 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/21 16:51:24 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	single_parser(char *line)
{
	char	**tab;
	t_list	**a;

	tab = ft_split(line, ' ');
	a = _lst();
	if (!tab)
		return (ft_putendl_fd("Error", 2), exit(1));
	check_input(tab);
	insert_list(tab);
	turkish(a);
}

void	multiple_parser(char **av, int ac)
{
	t_list	**a;

	a = _lst();
	check_multiple(av, ac);
	insert_args(av, ac);
	turkish(a);
}
