/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 07:36:46 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/30 15:09:48 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		n_a;
	int		n_b;

	tmpa = *stack_a;
	tmpb = *stack_b;
	n_a = stack_size(tmpa);
	n_b = stack_size(tmpb);
	while (tmpb)
	{
		tmpb -> b = tmpb -> position;
		if (tmpb -> position > n_b / 2)
			tmpb -> b = (n_b - tmpb -> position) * -1;
		tmpb -> a = tmpb -> pos_target;
		if (tmpb -> pos_target > n_a / 2)
			tmpb -> a = (n_a - tmpb -> pos_target) * -1;
		tmpb = tmpb -> next;
	}
}

void	move_cheapestt(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		chp;
	int		a;
	int		b;

	tmp = *stack_b;
	chp = INT_MAX;
	while (tmp)
	{
		if (absolute_nb(tmp -> a) + absolute_nb(tmp -> b)
			< absolute_nb(chp))
		{
			chp = absolute_nb(tmp -> b) + absolute_nb(tmp -> a);
			a = tmp -> a;
			b = tmp -> b;
		}
		tmp = tmp -> next;
	}
	move_stacks(stack_a, stack_b, a, b);
}
