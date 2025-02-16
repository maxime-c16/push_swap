/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:12:12 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/16 13:37:19 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_int_range(char *tab)
{
	long	nb;

	nb = ft_atol(tab);
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	return (0);
}

static int	check_duplicates(char **tab)
{
	int	i;
	int	j;

	i = 0;
	if (!tab)
		return (1);
	while (tab[i])
	{
		j = i + 1;
		if (!str_is_digit(tab[i]) || check_int_range(tab[i]))
			return (1);
		while (tab[j])
		{
			if (!ft_strcmp(tab[i], tab[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	check_input(char **tab)
{
	if (check_duplicates(tab))
	{
		ft_free_tab(tab);
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

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
