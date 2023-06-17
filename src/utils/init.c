/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 04:48:16 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/12 20:50:47 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	max_min_check(long int nb, t_stack *stack_a)
{
	if (nb > INT_MAX || nb < INT_MIN)
		exit_error(&stack_a, NULL);
}

static void	is_stack_create(long int nb, int is_cr, t_stack *stack_a)
{
	if (is_cr == 0)
	{
		stack_a = create_new_stack((int)nb);
		is_cr = 1;
	}
}

t_stack	*stack_values(int ac, char **av)
{
	t_stack			*stack_a;
	long int		nb;
	int				i;
	char			**str;
	int				is_stack_created;

	stack_a = NULL;
	i = 1;
	is_stack_created = 0;
	while (i < ac)
	{
		str = ft_split(av[i++], ' ');
		if (!str)
			exit_error(&stack_a, NULL);
		if (str[0] == NULL)
			exit_error(&stack_a, NULL);
		while (*str)
		{
			if (!ft_isdigit(**str) && **str != '-' && **str != '+')
				exit_error(&stack_a, NULL);
			nb = ft_atoi(*str++);
			max_min_check(nb, stack_a);
			is_stack_create(nb, is_stack_created, stack_a);
			add_element_bottom(&stack_a, create_new_stack((int)nb));
		}
	}
	return (stack_a);
}

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
