/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:21:45 by mcauchy           #+#    #+#             */
/*   Updated: 2025/05/12 14:45:23 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insert_list(char **tab)
{
	t_list	**lst;
	t_list	*tmp;
	int		i;

	i = 0;
	lst = _lst();
	while (tab[i])
	{
		tmp = ft_lstnew(ft_atoi(tab[i]));
		if (!tmp)
		{
			ft_lstclear(lst, NULL);
			ft_free_tab(tab);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		ft_lstadd_back(lst, tmp);
		i++;
	}
	ft_free_tab(tab);
}

void	insert_args(char **av, int ac)
{
	t_list	**lst;
	t_list	*tmp;
	int		i;

	i = 0;
	lst = _lst();
	while (i < ac)
	{
		tmp = ft_lstnew(ft_atoi(av[i]));
		if (!tmp)
		{
			ft_lstclear(lst, NULL);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		ft_lstadd_back(lst, tmp);
		i++;
	}
}
