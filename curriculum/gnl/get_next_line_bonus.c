/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:13:26 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/28 16:36:59 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*clear_storage(char *storage)
{
	if (storage)
		free(storage);
	return (NULL);
}

static char	*read_and_store(int fd, char *storage)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (clear_storage(storage));
	bytes_read = 1;
	while (!gnl_strchr(storage, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			storage = gnl_concat(storage, buffer);
		}
	}
	free(buffer);
	if (bytes_read < 0)
		return (clear_storage(storage));
	return (storage);
}

static char	*extract_line(char *storage)
{
	char	*line;
	size_t	len;

	if (!storage || !*storage)
		return (NULL);
	line = gnl_strchr(storage, '\n');
	if (line)
		len = (line - storage) + 1;
	else
		len = gnl_strlen(storage);
	return (gnl_substr(storage, 0, len));
}

static char	*update_storage(char *storage)
{
	char	*line;
	char	*new_storage;

	line = gnl_strchr(storage, '\n');
	if (!line)
		return (clear_storage(storage));
	new_storage = gnl_strdup(line + 1);
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[FOPEN_MAX + 1];
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = read_and_store(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = extract_line(storage[fd]);
	if (!line)
	{
		clear_storage(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	storage[fd] = update_storage(storage[fd]);
	return (line);
}
