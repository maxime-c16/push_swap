/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:19:39 by mcauchy           #+#    #+#             */
/*   Updated: 2025/05/15 13:19:14 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (nb == LONG_MAX)
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
			if (!ft_strcmp(tab[i], tab[j]) || \
				ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_input(char **tab)
{
	if (check_duplicates(tab))
	{
		ft_free_tab(tab);
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

void	check_multiple(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		if (!str_is_digit(av[i]) || check_int_range(av[i]))
		{
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		while (j < ac)
		{
			if (!ft_strcmp(av[i], av[j]) || ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_putendl_fd("Error", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
