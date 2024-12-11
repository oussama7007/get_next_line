/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:30:29 by oait-si-          #+#    #+#             */
/*   Updated: 2024/12/11 10:50:44 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *read_file(int fd, char **static_buffer)
{
    char    *buffer;
    int     bytes;
    
    buffer = malloc((size_t)BUFFER_SIZE)
}
char *new_line(char **static_buffer);
char *next_line(char **static_buffer);
char    *get_next_line(int fd)
{
    char static *buffer[OPEN_MAX];
    char *line;

    if(fd < 0 || BUFFER_SIZE > INT_MAX || BUFFER_SIZE < 0
        || read(fd, 0, 0) < 0)
        return(free(buffer[fd]), buffer[fd]= NULL, NULL);
    buffer[fd] = read_file(fd, &buffer[fd]);
    if(!buffer[fd])
        return(free(buffer[fd]), NULL);
    line = new_line(&buffer[fd]);
    if(!line)
        return(free(buffer[fd], buffer[fd] = NULL, NULL));
    buffer[fd] = next_line(&buffer[fd]);
    return(line);
}