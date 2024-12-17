/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:30:29 by oait-si-          #+#    #+#             */
/*   Updated: 2024/12/16 10:32:38 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*new__line(char *static_buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!static_buffer || !static_buffer[i])
		return (NULL);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*next__line(char *static_buffer)
{
	char	*new_line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
		return (free(static_buffer), NULL);
	new_line = malloc(ft_strlen(static_buffer) - i + 1);
	if (!new_line)
		return (free(static_buffer), NULL);
	i++;
	while (static_buffer[i])
		new_line[j++] = static_buffer[i++];
	new_line[j] = '\0';
	free(static_buffer);
	return (new_line);
}

char	*read__file(int fd, char **static_buffer)
{
	char	*buffer;
	int		bytes;
	char	*temp;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(*static_buffer), NULL);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), NULL);
		buffer[bytes] = '\0';
		temp = *static_buffer;
		*static_buffer = ft_strjoin(*static_buffer, buffer);
		if (!*static_buffer)
			return (free(temp), free(buffer), NULL);
		free(temp);
		if (ft_strchr(*static_buffer, '\n'))
			break ;
	}
	free(buffer);
	return (*static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd >= OPEN_MAX || fd < 0)
		return (NULL);
	if (BUFFER_SIZE > INT_MAX || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = read__file(fd, &buffer[fd]);
	if (!buffer[fd])
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	line = new__line(buffer[fd]);
	if (!line || *line == 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = next__line(buffer[fd]);
	return (line);
}
