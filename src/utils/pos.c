/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 05:46:54 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/30 09:01:46 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//assigns a position to each element in the stack
static void	position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp -> position = i;
		temp = temp -> next;
		i++;
	}
}

//returns the positions of the node with lowest index
int	get_the_lowest_index_position(t_stack **stack)
{
	t_stack	*curr;
	int		lowest_position;
	int		lowest_i;

	curr = *stack;
	lowest_i = INT_MAX;
	position(stack);
	lowest_position = curr -> position;
	while (curr)
	{
		if (curr -> index < lowest_i)
		{
			lowest_i = curr -> index;
			lowest_position = curr -> position;
		}
		curr = curr -> next;
	}
	return (lowest_position);
}

/*
takes a reference to the stack-a, index , target position then
return the position of the node in a with the smallest index
*/
static int	target(t_stack **a, int b_index, int target_indexn, int target_pos)
{
	t_stack	*tempa;

	tempa = *a;
	while (tempa)
	{
		if (tempa -> index > b_index && tempa -> index < target_indexn)
		{
			target_indexn = tempa -> index;
			target_pos = tempa -> position;
		}
		tempa = tempa -> next;
	}
	if (target_indexn != INT_MAX)
		return (target_pos);
	tempa = *a;
	while (tempa)
	{
		if (tempa -> index < target_indexn)
		{
			target_indexn = tempa -> index;
			target_pos = tempa -> position;
		}
		tempa = tempa -> next;
	}
	return (target_pos);
}

/*assign pos_target field to each node in the b_s
representing the position in the a stck where the node
should be moved.*/
void	target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		pos_target;

	tmp = *stack_b;
	position(stack_a);
	position(stack_b);
	pos_target = 0;
	while (tmp)
	{
		pos_target = target(stack_a, tmp -> index, INT_MAX, pos_target);
		tmp -> pos_target = pos_target;
		tmp = tmp -> next;
	}
}
