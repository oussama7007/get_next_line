/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:17:40 by oait-si-          #+#    #+#             */
/*   Updated: 2024/12/03 15:53:16 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Concatenate the buffer and the new data (buf), then free the original buffer
char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	// Join the existing buffer with the new buffer (buf)
	temp = ft_strjoin(buffer, buf);

	// Free the old buffer to prevent memory leaks
	free(buffer);

	// Return the newly concatenated string
	return (temp);
}

// This function processes the remaining data in the buffer after extracting a line
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	// Start scanning from the beginning of the buffer
	i = 0;

	// Find the position of the newline character or end of the buffer
	while (buffer[i] && buffer[i] != '\n')
		i++;

	// If no newline was found, it means the buffer is empty or fully processed
	if (!buffer[i])
	{
		// Free the buffer since it has no remaining data
		free(buffer);
		return (NULL);
	}

	// Allocate memory for the remaining part of the buffer (after the newline)
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));

	// Skip the newline character
	i++;
	j = 0;

	// Copy the remaining data after the newline into the new line buffer
	while (buffer[i])
		line[j++] = buffer[i++];

	// Free the original buffer as it is no longer needed
	free(buffer);

	// Return the remaining data to be processed
	return (line);
}

// This function extracts the current line from the buffer, including the newline
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	// Initialize the index variable
	i = 0;

	// If the buffer is empty, return NULL
	if (!buffer[i])
		return (NULL);

	// Find the end of the first line (stop at '\n' or end of string)
	while (buffer[i] && buffer[i] != '\n')
		i++;

	// Allocate memory for the extracted line, including space for the newline if present
	line = ft_calloc(i + 2, sizeof(char));

	// Copy the characters of the line from the buffer to the new line
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}

	// If a newline is found, append it to the extracted line
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';

	// Return the extracted line
	return (line);
}

// This function reads from the file descriptor and stores the data in the result buffer
char	*read_file(int fd, char *res) 
{
	char	*buffer;
	int		byte_read;

	// If res is NULL, initialize it to an empty string
	if (!res)
		res = ft_calloc(1, 1);

	// Allocate a temporary buffer for reading from the file
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));

	// Initialize byte_read to enter the loop
	byte_read = 1;

	// Loop to continuously read from the file until all data is processed
	while (byte_read > 0)
	{
		// Read up to BUFFER_SIZE bytes from the file descriptor
		byte_read = read(fd, buffer, BUFFER_SIZE);

		// If read failed (e.g., due to an error), free the buffer and return NULL
		if (byte_read == -1)
		{
			free(buffer);
			free(res);
			return (NULL);
		}

		// Null-terminate the string to safely handle the data
		buffer[byte_read] = 0;

		// Concatenate the new data (buffer) with the result (res) using ft_free
		res = ft_free(res, buffer);

		// If a newline character is found in the buffer, stop reading further
		if (ft_strchr(buffer, '\n'))
			break ;
	}

	// Free the temporary buffer as it is no longer needed
	free(buffer);

	// Return the updated result string with the newly read data
	return (res);
}

// Main function to get the next line from the file descriptor
char	*get_next_line(int fd)
{
	static char	*buffer; // Static buffer to store leftover data between function calls
	char		*line;

	// Return NULL if the file descriptor is invalid or BUFFER_SIZE is not positive
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{	
		if(buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	// Read from the file and update the buffer with new data
	buffer = read_file(fd, buffer);

	// If no data was read, return NULL (end of file or error)
	if (!buffer)
		return (NULL);

	// Extract the next line from the buffer
	line = ft_line(buffer);

	// Update the buffer to contain the remaining data (after the line)
	buffer = ft_next(buffer);

	// Return the extracted line
	return (line);
}
