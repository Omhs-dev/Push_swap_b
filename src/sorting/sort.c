/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:50:14 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/04 02:15:25 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//save three numbers in the stack a and push the rest int the stack b
static void	save_three_a_push_b(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_n;
	int	pushed;
	int	i;

	stack_n = stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_n > 6 && i < stack_n && pushed < stack_n / 2)
	{
		if ((*stack_a)->index <= stack_n / 2)
		{
			push_b(stack_a, stack_b);
			pushed++;
		}
		else
			rotate_a(stack_a);
		i++;
	}
	while (stack_n - pushed > 3)
	{
		push_b(stack_a, stack_b);
		pushed++;
	}
}

//after sorted turn the stack a until the lowest value is at the top
static void	turn_stack(t_stack **stack_a)
{
	int	lpos;
	int	stack_n;

	stack_n = stack_size(*stack_a);
	lpos = get_the_lowest_index_position(stack_a);
	if (lpos > stack_n / 2)
	{
		while (lpos < stack_n)
		{
			reverse_rotate_a(stack_a);
			lpos++;
		}
	}
	else
	{
		while (lpos > 0)
		{
			rotate_a(stack_a);
			lpos--;
		}
	}
}

//sort larger than 3
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	save_three_a_push_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		target_position(stack_a, stack_b);
		calculate_cost(stack_a, stack_b);
		move_cheapestt(stack_a, stack_b);
	}
	if (!sort_checked(*stack_a))
		turn_stack(stack_a);
	return ;
}
