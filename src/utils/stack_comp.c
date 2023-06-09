/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:28:02 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/08 16:42:52 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*create_new_stack(int data)
{
	t_stack	*newstack;

	newstack = malloc(sizeof * newstack);
	if (!newstack)
		return (NULL);
	newstack -> data = data;
	newstack -> a = -1;
	newstack -> b = -1;
	newstack -> index = 0;
	newstack -> position = -1;
	newstack -> pos_target = -1;
	newstack -> next = NULL;
	return (newstack);
}

t_stack	*get_last_element(t_stack *stack)
{
	while (stack && stack -> next != NULL)
		stack = stack -> next;
	return (stack);
}

t_stack	*get_beforelast_element(t_stack *stack)
{
	while (stack && stack -> next && stack -> next -> next != NULL)
		stack = stack -> next;
	return (stack);
}

void	add_element_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = get_last_element(*stack);
	last -> next = new;
}

//move in
int	stack_size(t_stack *stack)
{
	int	n;

	n = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack -> next;
		n++;
	}
	return (n);
}
