/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:51:17 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/17 11:44:35 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

t_list	**_lst(void);

void	ft_free_tab(char **tab);
void	single_parser(char *line);
void	multiple_parser(char **av, int ac);

void	insert_args(char **av, int ac);
void	insert_list(char **tab);

void	check_input(char **tab);
void	check_multiple(char **av, int ac);

void	print_list(void);

#endif
