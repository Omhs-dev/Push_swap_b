/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:06:09 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/10 19:22:16 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long int	ft_atoi(const char *str)
{
	int			i;
	long int	opr;
	int			sign;

	i = 0;
	if ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	opr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		opr = opr * 10 + (str[i] - '0');
		i++;
	}
	return (opr * sign);
}
