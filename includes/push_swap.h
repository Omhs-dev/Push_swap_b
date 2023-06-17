/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:28:43 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/12 21:08:14 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include <stdlib.h>
# include "../bonus/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	int				a;
	int				b;
	int				position;
	int				pos_target;
	int				index;
	struct s_stack	*next;
}		t_stack;

// static void	push(t_stack **stack_src, t_stack **stack_dst);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
// static void	rotate(t_stack *stack_cntn);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack *stack_cntn);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_src, t_stack **stack_dst);
void	rotate(t_stack **stack_cntn);
void	reverse_rotate(t_stack **stack_cntn);
//e
t_stack	*create_new_stack(int data);
t_stack	*get_last_element(t_stack *stack);
t_stack	*get_beforelast_element(t_stack *stack);
void	add_element_bottom(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
//r
void	calculate_cost(t_stack **stack_a, t_stack **stack_b);
void	move_stacks(t_stack **as, t_stack **bs, int a, int b);
void	move_cheapestt(t_stack **stack_a, t_stack **stack_b);
// static void reverse_rotate(t_stack **stack_cntn);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_rrr(t_stack **stack_a, t_stack **stack_b);
//eee
t_stack	*stack_values(int num_arg, char **arr_str);
// t_stack	*stack_values(t_stack **ac, char **av);
void	indexation(t_stack *stack_a, int size);
//d
// static int is_number(char *av);
// static int duplicates_check(char **av);
// static int arg_zero(char *av);
int		is_parser_error(int arc);
int		ft_issign(char c);
//g
// static void rev_rotate_ab(t_stack **as, t_stack **bs, int *a, int *b);
// static void rotate_rab(t_stack **as, t_stack **bs, int *a, int *b);
// static void rotate_ra(t_stack **as, int *a);
// static void rotate_rb(t_stack **bs, int *b);
//y
// static void position(t_stack **stack);
int		get_the_lowest_index_position(t_stack **stack);
void	target_position(t_stack **stack_a, t_stack **stack_b);
//h
int		ft_isdigit(char c);
int		ft_issign(char c);
int		ft_strcmp_nb(const char *s1, const char *s2);
int		absolute_nb(int nb);
void	ft_putstr(char *s);
//d
// static int	blanks(const char c);
long	int	ft_atoi(const char *str);
//op
// static int high_index(t_stack *stack);
void	sort_three(t_stack **stack);
// static void save_three_a_push_b(t_stack **stack_a, t_stack **stack_b);
// static void turn_stack(t_stack **stack_a);
void	sort(t_stack **stack_a, t_stack **stack_b);
//m
int		sort_checked(t_stack *stack);
// static void push_swap(t_stack **stack_a, t_stack **stack_b, int stack_n);
// int main (int ac, char **av);

void	free_stack(t_stack **stack);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
// void parse_multiple_args(int argc, char **argv, t_stack *ps);
// t_stack	*create_stack(int value, t_stack **stack, int *is_created);
t_stack	*create_stack(int value, t_stack **stack);
/* split */
char	**ft_split(char *str, char del);
int		ft_strlen(char *str);
t_stack	*split_values(int ac, char **av);
int		correct_input(char **av);
int		is_number(char *av);
// void printLinkedList(Node* head);
//bonus
int		exec(char *input, t_stack *stack_a, t_stack *stack_b);
t_stack	*stack_values_check(int ac, char **av);
void	input(t_stack *stack_a, t_stack *stack_b);
// void	input(t_stack *stack_a);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);

#endif