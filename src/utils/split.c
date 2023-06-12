/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:40:18 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/12 20:48:51 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	count_words(char *str, char dlm)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != dlm)
		{
			count++;
			while (str[i] != dlm && str[i + 1])
				i++;
		}
		i++;
	}
	return (count);
}

static char	*get_words(char *str, char dlm)
{
	int		i;
	char	*mem;
	int		j;

	i = 0;
	while (str[i] != dlm && str[i])
		i++;
	mem = (char *)malloc(sizeof(char) * (i + 1));
	if (!mem)
		return (NULL);
	j = 0;
	while (str[j] != dlm && str[j])
	{
		mem[j] = str[j];
		j++;
	}
	mem[j] = '\0';
	return (mem);
}

static char	**free_mem(char **str, int dlm)
{
	while (str)
	{
		free(str[dlm]);
		dlm--;
	}
	free(str);
	return (NULL);
}

static char	**mem_fill(char *str, char d)
{
	char	**mem;

	if (!str)
		return (NULL);
	mem = (char **)malloc(sizeof(char *) * (count_words(str, d) + 1));
	if (!mem)
		return (NULL);
	return (mem);
}

char	**ft_split(char *s, char c)
{
	char	**memm;
	int		j;

	memm = mem_fill(s, c);
	if (!memm)
		return (NULL);
	while (*s && *s == c)
		s++;
	j = 0;
	while (*s)
	{
		memm[j] = get_words(&*s, c);
		if (!memm[j])
		{
			free_mem(memm, j);
			return (NULL);
		}
		j++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	memm[j] = NULL;
	return (memm);
}

// int main (void)
// {
//         int i = 0;
//         char *test = " ";
//         char    sep = ' ';
//         char    **split = ft_split(test, sep);
//         while (split[i])
//         {
//             printf("split %d : %s\n",i,split[i]);
//             i++;
//         }
//         if (split[0] == NULL)
// 			printf("null");
// }
