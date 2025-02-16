/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:21:45 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/16 13:30:29 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Inserts the values from the given array of strings into a linked list.
 *
 * This function takes an array of strings `tab` and creates a new linked list
 * `list` by parsing each string as an integer and adding it to the list. If
 * any errors occur during the process, such as memory allocation failure or
 * invalid input, the function will clear the list, free the tab, print an
 * error message, and exit the program.
 *
 * @param tab An array of strings containing the values to be inserted into the
 *  list.
 */
void	insert_list(char **tab)
{
	t_list	**lst;
	t_list	*tmp;
	int		i;

	i = 0;
	lst = _lst();
	print_list();
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

void	print_list(void)
{
	t_list	**lst;

	lst = _lst();
	if (!*lst)
		return ;
	while (*lst)
	{
		if (!(*lst)->next)
			printf("%d -> (null)\n", (*lst)->value);
		else
			printf("%d -> ", (*lst)->value);
		(*lst) = (*lst)->next;
	}
}
