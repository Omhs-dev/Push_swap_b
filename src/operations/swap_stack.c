/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:05:50 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/30 15:25:13 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack *stack_cntn)
{
	int	tmp;

	if (stack_cntn == NULL || stack_cntn -> next == NULL)
		return ;
	tmp = stack_cntn -> data;
	stack_cntn -> data = stack_cntn -> next -> data;
	stack_cntn -> next -> data = tmp;
	tmp = stack_cntn -> index;
	stack_cntn -> index = stack_cntn -> next -> index;
	stack_cntn -> next -> index = tmp;
}

void	swap_a(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
