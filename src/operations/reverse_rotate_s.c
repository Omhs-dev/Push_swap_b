/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 02:03:03 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/30 15:38:28 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// static void reverse_rotate(t_stack **stack_cntn)
// {
// 	t_stack	*tmp;
// 	t_stack	*last;
// 	t_stack	*before_last;

// 	last = get_last_element(*stack_cntn);
// 	before_last = get_beforelast_element(*stack_cntn);
// 	tmp = *stack_cntn;
// 	*stack_cntn = last;
// 	(*stack_cntn)->next = tmp;
// 	before_last->next = NULL;
// }

static void	reverse_rotate(t_stack **stack_cntn)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_last_element(*stack_cntn);
	before_tail = get_beforelast_element(*stack_cntn);
	tmp = *stack_cntn;
	*stack_cntn = tail;
	(*stack_cntn)->next = tmp;
	before_tail->next = NULL;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	reverse_rotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr\n");
}
