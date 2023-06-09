/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:48:16 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/09 17:11:39 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

static int	is_number(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]) && av[i + i] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

t_stack	*stack_values(int ac, char **av)
{
	t_stack	*stack_a;
	long int		nb;
	int				i;
	char			**str;
	int is_stack_created;

	i = 1;
	is_stack_created = 0;
	while (i < ac)
	{
		str = ft_split(av[i++], ' ');
		if (!str)
			exit_error(&stack_a, NULL);
		while (*str)
		{
			if (!is_number(*str))
				exit_error(&stack_a, NULL);
			nb = ft_atoi(*str);
			if (nb > INT_MAX || nb < INT_MIN)
				exit_error(&stack_a, NULL);
			if (is_stack_created == 0)
				stack_a = create_new_stack((int)nb);
			else
				add_element_bottom(&stack_a, create_new_stack((int)nb));
			str++;
		}
		is_stack_created = 1;
	}
	return (stack_a);
}

// t_stack *split_values(int ac, char **av)
// {
// 	char **str;
// 	int i;

// 	i = 1;
// 	str = ft_split(av[i], ' ');
// 	if (*str == NULL)
// 		exit(EXIT_FAILURE);
// 	while (*str)
// 	{
// 		stack_values(ac, av);
// 		str++;
// 	}
// 	return (stack_values(ac, av));
// }

//fill stacck a with the provided values
// t_stack	*stack_values(int ac, char **av)
// {
// 	t_stack		*stack_a;
// 	long int	nb;
// 	int			i;
// 	char **str;
// 	char **tmp;

// 	stack_a = NULL;
// 	nb = 0;
// 	i = 1;
// 	str = ft_split(av[i], ' ');
// 	tmp = str;
// 	while (i < ac && *str)
// 	{
// 		nb = ft_atoi(*str);
// 		if (nb > INT_MAX || nb < INT_MIN)
// 			exit_error(&stack_a, NULL);
// 		if (i == 1)
// 		{
// 			stack_a = create_new_stack((int)nb);
// 		}
// 		else
// 			add_element_bottom(&stack_a, create_new_stack((int)nb));
// 		i++;
// 	}
// 	return (stack_a);
// }

//assign an index go each value in the stack a.
void	indexation(t_stack *stack_a, int size)
{
	t_stack	*hgh;
	t_stack	*ptr;
	int		data;

	while (--size > 0)
	{
		ptr = stack_a;
		data = INT_MIN;
		hgh = NULL;
		while (ptr)
		{
			if (ptr -> data == INT_MIN && ptr -> index == 0)
				ptr -> index = 1;
			if (ptr -> data > data && ptr -> index == 0)
			{
				data = ptr -> data;
				hgh = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr -> next;
		}
		if (hgh != NULL)
			hgh -> index = size;
	}
}
