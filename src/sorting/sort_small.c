/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:37:12 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/03 16:28:12 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*take a pointer to a stack and returns the index of 
the highest element in the stack*/
static int	high_index(t_stack *stack_i)
{
	int		index;

	index = stack_i->index;
	while (stack_i)
	{
		if (stack_i->index > index)
			index = stack_i->index;
		stack_i = stack_i->next;
	}
	return (index);
}

void	sort_three(t_stack **stack)
{
	int	high;

	if (sort_checked(*stack))
		return ;
	high = high_index(*stack);
	if ((*stack)-> index == high)
		rotate_a(stack);
	if ((*stack)-> next -> index == high)
		reverse_rotate_a(stack);
	if ((*stack)-> index > (*stack)->next -> index)
		swap_a(stack);
}
