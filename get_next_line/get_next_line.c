/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:29:05 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/21 15:15:00 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*final;

	final = malloc(nmemb * size);
	if (!final)
		return (NULL);
	ft_bzero(final, nmemb * size);
	return (final);
}

// function that reads the file, 
// stores the str in the buffer and joins it to the stash

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

// function(s) that gets the str to return and removes it from the stash

int	get_size(char *stashfd)
{
	char	*nl;
	size_t	len;

	nl = ft_strchr(stashfd, '\n');
	if (!nl || *(nl + 1) == '\0' || nl == stashfd)
		return (ft_strlen(stashfd));
	len = ft_strlen(stashfd) - ft_strlen(nl);
	return (len);
}

void	get_result(char **stash, char **result)
{
	char	*nl;
	char	*tmp;
	size_t	i;

	nl = ft_strchr(*stash, '\n');
	if (!nl || !(nl + 1) || nl == *stash)
	{
		free(*result);
		*result = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		return ;
	}
	i = 0;
	while ((*stash + i) != (nl + 1))
	{
		(*result)[i] = (*stash)[i];
		i++;
	}
	(*result)[i] = '\0';
	tmp = ft_strdup((*stash + i));
	free(*stash);
	*stash = tmp;
}

// get_next_line

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FILES_OPENED];
	char		*result;
	
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	while (ft_strchr(stash[fd], '\n') == NULL && read_buffer(fd, &(stash[fd])) > 0)
		;
	if (ft_strlen(stash[fd]) == 0)
		return (NULL);
	result = (char *)ft_calloc((get_size(stash[fd]) + 1), sizeof(char));
	if (!result)
		return (NULL);
	get_result(&(stash[fd]), &result);
	if (stash[fd] == 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (result);
}

/*
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = '\0';
		i++;
	}
}

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

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*dest;

	i = ft_strlen(s) + 1;
	j = 0;
	dest = malloc(i * sizeof(char));
	if (!dest)
		return (0);
	while (s[j] != '\0')
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
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
	str = get_next_line(fd);
	printf("result:	%s\n", str);
	//str = get_next_line(fd2);
	//printf("result:	%s\n", str);
	//read(fd, str, 30);
	//printf("result: %s\n", str);
}
*/