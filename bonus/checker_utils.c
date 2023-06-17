/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:17:00 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/05 00:17:00 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "./get_next_line_bonus.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				len1;
	int				len2;
	size_t			i;

	if (n == 0)
		return (0);
	len1 = ft_strlen_g(s1);
	len2 = ft_strlen_g(s2);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] == str2[i] && (str1[i] != '\0'
			&& str2[i] != '\0') && i < n - 1)
	{
			len1++;
			len2++;
			i++;
	}
	return ((str1[i]) - (str2[i]));
	return (0);
}

// t_stack	*create_stack_from_string(char *str)
// {
// 	t_stack		*stack;
// 	long int	nb;

// 	stack = NULL;
// 	while (*str)
// 	{
// 		if (!ft_isdigit(*str) && *str != '-' && *str != '+')
// 			exit_error(&stack, NULL);
// 		nb = ft_atoi(str);
// 		if (nb > INT_MAX || nb < INT_MIN)
// 			exit_error(&stack, NULL);
// 		if (stack == NULL)
// 			stack = create_new_stack((int)nb);
// 		else
// 			add_element_bottom(&stack, create_new_stack((int)nb));
// 		while (*str && *str != ' ')
// 			str++;
// 		if (*str)
// 			str++;
// 	}
// 	return (stack);
// }

// t_stack	*stack_values_check(int ac, char **av)
// {
// 	t_stack	*stack_a;
// 	int		i;
// 	char	**str;

// 	stack_a = NULL;
// 	i = 1;
// 	while (i < ac)
// 	{
// 		str = ft_split(av[i], ' ');
// 		if (str == NULL)
// 			exit_error(&stack_a, NULL);
// 		while (*str)
// 		{
// 			stack_a = create_stack_from_string(*str);
// 			str++;
// 		}
// 		i++;
// 	}
// 	return (stack_a);
// }
static void	max_min_check(long int nb, t_stack *stack_a)
{
	if (nb > INT_MAX || nb < INT_MIN)
		exit_error(&stack_a, NULL);
}

static void	is_stack_create(long int nb, int is_cr, t_stack *stack_a)
{
	if (is_cr == 0)
	{
		stack_a = create_new_stack((int)nb);
		is_cr = 1;
	}
}

t_stack	*stack_values_check(int ac, char **av)
{
	t_stack			*stack_a;
	long int		nb;
	int				i;
	char			**str;
	int				is_stack_created;

	stack_a = NULL;
	i = 1;
	is_stack_created = 0;
	while (i < ac)
	{
		str = ft_split(av[i++], ' ');
		if (!str)
			exit_error(&stack_a, NULL);
		if (str[0] == NULL)
			exit_error(&stack_a, NULL);
		while (*str)
		{
			if (!ft_isdigit(**str) && **str != '-' && **str != '+')
				exit_error(&stack_a, NULL);
			nb = ft_atoi(*str++);
			max_min_check(nb, stack_a);
			is_stack_create(nb, is_stack_created, stack_a);
			add_element_bottom(&stack_a, create_new_stack((int)nb));
		}
	}
	return (stack_a);
}

void	input(t_stack *stack_a, t_stack *stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (!exec(input, stack_a, stack_b))
		{
			write(2, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		input = get_next_line(0);
	}
	return ;
}
