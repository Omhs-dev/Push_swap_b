/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:17:08 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/05 00:17:08 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "./get_next_line_bonus.h"

int	exec(char *input, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(input, "sa\n", 4) == 0)
		swap(stack_a);
	else if (ft_strncmp(input, "sb\n", 4) == 0)
		swap(stack_b);
	else if (ft_strncmp(input, "ss\n", 4) == 0)
		swap_ss(&stack_a, &stack_b);
	else if (ft_strncmp(input, "pa\n", 4) == 0)
		push(&stack_b, &stack_a);
	else if (ft_strncmp(input, "pb\n", 4) == 0)
		push(&stack_a, &stack_b);
	else if (ft_strncmp(input, "ra\n", 4) == 0)
		rotate(&stack_a);
	else if (ft_strncmp(input, "rb\n", 4) == 0)
		rotate(&stack_b);
	else if (ft_strncmp(input, "rra\n", 4) == 0)
		reverse_rotate(&stack_a);
	else if (ft_strncmp(input, "rrb\n", 4) == 0)
		reverse_rotate(&stack_b);
	else
	{
		free(input);
		return (0);
	}
	free(input);
	return (1);
}

static int	issort_checked(t_stack *stack)
{
	while (stack -> next != NULL)
	{
		if (stack -> data > stack -> next -> data)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

static void	ft_check_duplicates(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack_a;
	while (tmp)
	{
		tmp2 = tmp -> next;
		while (tmp2)
		{
			if (tmp -> data == tmp2 -> data)
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			tmp2 = tmp2 -> next;
		}
		tmp = tmp -> next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (is_parser_error(argc))
		return (0);
	stack_b = NULL;
	stack_a = stack_values(argc, argv);
	ft_check_duplicates(stack_a);
	input(stack_a, stack_b);
	if (issort_checked(stack_a) && stack_b == NULL)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
