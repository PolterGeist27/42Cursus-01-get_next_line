/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:29:09 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/17 11:14:00 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef MAX_FILES_OPENED
#  define MAX_FILES_OPENED 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//  get_next_line.c
char	*get_next_line(int fd);

//  get_next_line_utils.c
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
