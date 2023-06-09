/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:19:05 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/30 08:33:15 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_ra(t_stack **as, int *a)
{
	while (*a)
	{
		if (*a > 0)
		{
			rotate_a(as);
			(*a)--;
		}
		else if (*a < 0)
		{
			reverse_rotate_a(as);
			(*a)++;
		}
	}
}

static void	rotate_rb(t_stack **bs, int *b)
{
	while (*b)
	{
		if (*b > 0)
		{
			rotate_b(bs);
			(*b)--;
		}
		else if (*b < 0)
		{
			reverse_rotate_b(bs);
			(*b)++;
		}
	}
}

static void	rev_rotate_ab(t_stack **as, t_stack **bs, int *a, int *b)
{
	while (*a < 0 && *b < 0)
	{
		(*a)++;
		(*b)++;
		reverse_rotate_rrr(as, bs);
	}
}

static void	rotate_rab(t_stack **as, t_stack **bs, int *a, int *b)
{
	while (*a > 0 && *b > 0)
	{
		(*a)--;
		(*b)--;
		rotate_rr(as, bs);
	}
}

void	move_stacks(t_stack **as, t_stack **bs, int a, int b)
{
	if (a < 0 && b < 0)
		rev_rotate_ab(as, bs, &a, &b);
	else if (a > 0 && b > 0)
		rotate_rab(as, bs, &a, &b);
	rotate_ra(as, &a);
	rotate_rb(bs, &b);
	push_a(as, bs);
}
