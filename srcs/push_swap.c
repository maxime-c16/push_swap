/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:50:47 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/16 11:35:42 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		single_parser(av[1]);
	else if (ac > 2)
		multiple_parser(av + 1, ac - 1);
	else
		return (ft_putendl_fd("Error", 2), 1);
	return (0);
}
