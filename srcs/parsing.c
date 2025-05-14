/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:12:12 by mcauchy           #+#    #+#             */
/*   Updated: 2025/05/12 14:45:23 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	single_parser(char *line)
{
	char	**tab;

	if (!line || !*line || check_spaces(line))
		return (ft_putendl_fd("Error", 2), exit(1));
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
