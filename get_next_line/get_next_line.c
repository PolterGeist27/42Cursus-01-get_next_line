/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:29:05 by diogmart          #+#    #+#             */
/*   Updated: 2022/11/14 11:59:54 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	-Create a function that reads the next line of a file;
	-You can use malloc(), read() and free();
	-Repeated calls of the function should let you read
	the text file pointed to by fd *One line at a time*;
	-If there is nothing else to read or if an error occurred,
	it should return NULL;
*/

char	*get_next_line(int fd)
{
	char	*final;
	static char	*stash;
}

/*
#include <stdio.h>

int	main()
{
}
*/