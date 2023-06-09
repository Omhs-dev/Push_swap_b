/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:32:41 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/05 01:45:55 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//read from fd and append data to str until '\n' or end of the file
char	*read_str(int fd, char *str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

//return the remainder as string of l_str after encounter newline caracter '\n'
char	*remained_str_new(char *l_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (l_str[i] && l_str[i] != '\n')
		i++;
	if (!l_str[i])
	{
		free(l_str);
		return (NULL);
	}
	j = ft_strlen_g(l_str) - i;
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, &l_str[i + 1], j);
	str[j] = '\0';
	free(l_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = read_str(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = get_the_line(buff[fd]);
	buff[fd] = remained_str_new(buff[fd]);
	if (!buff[fd] && !line)
	{
		free(line);
		free(buff[fd]);
		buff[fd] = NULL;
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	// int		fd2;
// 	// int		fd3;
// 	fd1 = open("read_error.txt", O_RDONLY);
// 	// fd2 = open("tests/test2.txt", O_RDONLY);
// 	// fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		// line = get_next_line(fd2);
// 		// printf("line [%02d]: %s", i, line);
// 		// free(line);
// 		// line = get_next_line(fd3);
// 		// printf("line [%02d]: %s", i, line);
// 		// free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	system("leaks a.out");
// 	// close(fd2);
// 	// close(fd3);
// 	return (0);
// }
