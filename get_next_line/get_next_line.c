/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:50:33 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/22 10:52:16 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_buffer(int	fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (bytes);
	tmp = ft_strjoin(*stash, buffer);
	free(*stash);
	*stash = tmp;
	return (bytes);
}

int	find_first_newline(char *str, char c)																																																																																																																																																																																																																																																																																																																																											
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void	remove_result(char **stash)
{
	char	*nl;
	char	*tmp;
	size_t	i;
	size_t	j;

	nl = ft_strchr(*stash, '\n');
	if (!nl)
	{
		free(*stash);
		*stash = NULL;
		return ;
	}
	tmp = malloc((ft_strlen(nl)) * sizeof(char));
	i = 0;
	j = ft_strlen(*stash) - ft_strlen(nl) + 1;
	while (j < ft_strlen(*stash))
	{
		tmp[i] = (*stash)[j];
		j++;
		i++;
	}
	tmp[i] = '\0';
	free(*stash);
	*stash = tmp;
}

void	get_result(char **stash, char **result)
{
	char	*nl;
	size_t	len;
	size_t	i;

	nl = ft_strchr(*stash, '\n');
	len = ft_strlen(*stash) - ft_strlen(nl) + 2;
	*result = (char *)malloc(len * sizeof(char));
	if (!result)
		return ;
	i = 0;
	while (i < len - 1)
	{
		(*result)[i] = (*stash)[i];
		i++;
	}
	(*result)[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FILES_OPENED];
	char		*result;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_strchr(stash[fd], '\n') == NULL && read_buffer(fd, &(stash[fd])))
		;
	if (ft_strlen(stash[fd]) == 0)
		return (NULL);
	get_result(&(stash[fd]), &result);
	remove_result(&(stash[fd]));
	return (result);
}