/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:13:26 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/19 19:03:06 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*clear_storage(char *storage)
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
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_and_store(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
	{
		clear_storage(storage);
		storage = NULL;
		return (NULL);
	}
	storage = update_storage(storage);
	return (line);
}
