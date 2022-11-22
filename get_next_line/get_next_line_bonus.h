/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:50:29 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/22 15:00:28 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

//	 MAX_FILES_OPENED is the locked-in-memory size
//	 obtained through the command "ulimit -a"
# ifndef MAX_FILES_OPENED
#  define MAX_FILES_OPENED 65536
# endif

//	Value can be changed at compile time
//	by adding "-D BUFFER_SIZE=n" to the compiler call
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//  get_next_line.c
char	*get_next_line(int fd);

//  get_next_line_utils.c
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
