/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:54:46 by mdalloli          #+#    #+#             */
/*   Updated: 2024/12/02 13:54:48 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*legge dal file in un buff e aggiunge i dati a un stringa 
finche' non trova \n o \0 */
char	*ft_read_to_str(int fd, char *str)
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

/* gestisce il processo di ottenere una singola riga d un file, mantenendo 
i dati rimanenti in una variabile statica */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_to_left_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_extract_line(str);
	str = ft_new_left_str(str);
	return (line);
}
