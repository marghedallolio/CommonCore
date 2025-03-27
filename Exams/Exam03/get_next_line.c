/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:38:04 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/24 15:38:17 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name : get_next_line
Expected files : get_next_line.c
Allowed functions: read, free, malloc
--------------------------------------------------------------------------------

Write a function named get_next_line which prototype should be:
char *get_next_line(int fd);


Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succesion of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

Caling your function get_next_line in a lop will therefore allow you to read the text avaiable on a file descriptor one line at a time until the end of the text, no matter the size od either the text or one of its lines.

Make sure that your function behaves wel when it reads from a file, from the standard output, from a redirection, etc...

No call to another function will be done on the file descriptor between 2 calls of get_next_line. Finally we consider that get_next_line has an undefined behaviour when reading from a binary file.*/


#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
static char *ft_strdup(const char *s)
{
	char    *dup;
	int     i = 0;
	while (s[i])
		i++;
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
static char *ft_strjoin(char *s1, char *s2)
{
	int i = 0, j = 0;
	char *new_str;
	while (s1 && s1[i]) i++;
	while (s2[j]) j++;
	new_str = malloc(i + j + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}
char *get_next_line(int fd)
{
	static char *buffer;
	char temp[BUFFER_SIZE + 1], *line;
	int bytes_read;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && (bytes_read = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	if (!buffer || !*buffer)
		return (NULL);
	line = ft_strdup(buffer);
	free(buffer);
	buffer = NULL;
	return (line);
}
