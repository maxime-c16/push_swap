/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:17:43 by maximecauch       #+#    #+#             */
/*   Updated: 2025/02/16 12:43:09 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **alst, void (*del)(int))
{
	t_list	*ptr;

	if (!alst || !*alst)
		return ;
	while (*alst && alst)
	{
		ptr = (*alst)->next;
		ft_lstdelone(*alst, del);
		*alst = ptr;
	}
	return ;
}
