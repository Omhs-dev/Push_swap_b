/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:06:09 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/04 11:53:05 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	blanks(const char c)
{
	if (c == ' ' || c == '\n' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			i;
	long int	opr;
	int			sign;

	i = 0;
	while (blanks(str[i]))
		i++;
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

// void parse_multiple_args(int argc, char **argv, t_stack *ps)
// {
// 	int count;
// 	int value;

// 	count = 1;
// 	while (count < argc)
// 	{
// 		if (is_number(argv[count] == 0))
// 		{
// 			write(2, "error", 6);
// 			exit(EXIT_FAILURE);
// 		}
// 		value = ft_atoi(argv[count]);
// 		if (value > INT32_MAX || value < INT32_MAX)
// 		{
// 			write(2, "error", 6);
// 			exit(EXIT_FAILURE);
// 		}
// 		turn_stack(ps, value);
// 	}
// }
