/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:12:12 by mcauchy           #+#    #+#             */
/*   Updated: 2025/03/16 14:39:12 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	single_parser(char *line)
{
	char	**tab;

	tab = ft_split(line, ' ');
	if (!tab)
		return (ft_putendl_fd("Error", 2), exit(1));
	check_input(tab);
	insert_list(tab);
	normalize_list(_lst());
	radix_sort(_lst());
}

void	multiple_parser(char **av, int ac)
{
	check_multiple(av, ac);
	insert_args(av, ac);
	normalize_list(_lst());
	radix_sort(_lst());
}
