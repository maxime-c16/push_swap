/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:51:17 by mcauchy           #+#    #+#             */
/*   Updated: 2025/05/12 16:16:44 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

t_list	**_lst(void);

void	ft_free_tab(char **tab);
void	single_parser(char *line);
void	multiple_parser(char **av, int ac);

void	insert_args(char **av, int ac);
void	insert_list(char **tab);

void	check_input(char **tab);
void	check_multiple(char **av, int ac);

void	push(t_list **lst_from, t_list **lst_to);
void	swap(t_list **lst);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);

void	execute_movements(t_list **a, t_list **b, char *str);

void	normalize_list(t_list **lst);
void	radix_sort(t_list **lst);

void	free_singleton(void);
void	sort_small(int size, t_list **b);
void	sort_three(t_list **l);
void	sort_five(t_list **b);
int		is_sorted(t_list **lst);

#endif
