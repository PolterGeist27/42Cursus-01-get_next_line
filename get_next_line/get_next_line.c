/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:29:05 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/17 11:46:51 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// function that reads the file, 
// stores the str in the buffer and joins it to the stash

int	read_buffer(int	fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	tmp = ft_strjoin(*stash, buffer);
	*stash = tmp;
	return (bytes);
}

// function(s) that gets the str to return and removes it from the stash

int	get_size(char *stash)
{
	char	*nl;
	size_t	index;
	
	nl = ft_strchr(stash, '\n');
	index = ft_strlen(stash) - ft_strlen(nl) + 1;
	return (index);
}

void	get_result(char **stash, char **result)
{
	char	*nl;
	size_t	i;

	nl = ft_strchr(*stash, '\n');
	if (!nl)
	{
		(*result) = (*stash);
		*stash = NULL;
		return ;
	}
	i = 0;
	while ((*stash + i) != (nl + 1))
	{
		(*result)[i] = *(*stash + i);
		i++;
	}
	(*result)[i] = '\0';
	free(*stash);
	*stash = nl + 1;
}

// get_next_line

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FILES_OPENED];
	char		*result = NULL;
	
	while (!ft_strchr(stash[fd], '\n') && read_buffer(fd, &(stash[fd])) > 0);
	if (ft_strlen(stash[fd]) == 0)
		return (NULL);
	result = (char *)malloc(get_size(stash[fd]) * sizeof(char));
	if (!result)
		return (NULL);
	get_result(&(stash[fd]), &result);
	return (result);
}

/*
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *s1)
	{
		str[i++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	char	*str;
	char	*str2;
	char	*file = "test.txt";
	char	*file2 = "test2.txt";
	int	fd;
	int fd2;
	
	fd = open(file, 'r');
	fd2 = open(file2, 'r');
	str = get_next_line(fd);
	printf("result:	%s\n", str);
	str = get_next_line(fd2);
	printf("result:	%s\n", str);
	str = get_next_line(fd);
	printf("result:	%s\n", str);
	//read(fd, str, 30);
	//printf("result: %s\n", str);
}
*/