/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:58:24 by mcauchy           #+#    #+#             */
/*   Updated: 2025/05/15 14:02:44 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

#define UPPER_DIGIT 7
#define LOWER_DIGIT 8

long	ft_atol(const char *s)
{
	int		value;
	int		sign;
	_Bool	overflow;

	value = 0;
	sign = 1;
	overflow = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
		sign = 44 - *s++;
	while (ft_isdigit(*s) && !overflow)
	{
		value = value * 10 + *s++ - '0';
		if (ft_isdigit(*s) && (value > INT_MAX / 10
				|| (sign == 1 && value == INT_MAX / 10
					&& *s - '0' > UPPER_DIGIT)
				|| (sign == -1 && value == INT_MAX / 10
					&& *s - '0' > LOWER_DIGIT)))
			overflow = 1;
	}
	if (overflow)
		return (LONG_MAX);
	return (sign * value);
}
