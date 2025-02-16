/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:12:12 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/16 17:16:56 by mcauchy          ###   ########.fr       */
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
	print_list();
}

void	multiple_parser(char **av, int ac)
{
	ft_putendl_fd("multiple_parser", 2);
	return ;
}
