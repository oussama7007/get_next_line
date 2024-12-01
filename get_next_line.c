#include "get_next_line.h"

// Concatenate buffer and buf, then free the original buffer
char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	// Join buffer and buf into a new string
	temp = ft_strjoin(buffer, buf);
	// Free the old buffer to avoid memory leaks
	free(buffer);
	// Return the newly joined string
	return (temp);
}

// Remove the processed line from the buffer and keep the remaining data
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// Find the end of the first line (stop at '\n' or '\0')
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// If no newline is found, free the buffer and return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// Allocate memory for the remaining data after the first line
	// (length of buffer - first line + 1 for the null terminator)
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++; // Skip the newline character
	j = 0;
	// Copy the remaining data to the new line buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	// Free the old buffer
	free(buffer);
	// Return the remaining data as the new buffer
	return (line);
}

// Extract the current line to return from the buffer
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	// If the buffer is empty, return NULL
	if (!buffer[i])
		return (NULL);
	// Find the end of the line (stop at '\n' or '\0')
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// Allocate memory for the line (including '\n' and null terminator)
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// Copy the characters from the buffer to the line
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// Add the newline character if it exists in the buffer
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	// Return the extracted line
	return (line);
}

// Read from the file descriptor and store data in the buffer
char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	// If res is NULL, allocate an empty string
	if (!res)
		res = ft_calloc(1, 1);
	// Allocate a temporary buffer for reading
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1; // Initialize byte_read to enter the loop
	while (byte_read > 0)
	{
		// Read from the file descriptor
		byte_read = read(fd, buffer, BUFFER_SIZE);
		// If read fails, free the buffer and return NULL
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// Null-terminate the buffer to prevent memory issues
		buffer[byte_read] = 0;
		// Append the new data to the existing res and free the old res
		res = ft_free(res, buffer);
		// If a newline is found, stop reading further
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	// Free the temporary buffer and return the result
	free(buffer);
	return (res);
}

// Get the next line from the file descriptor
char	*get_next_line(int fd)
{
	static char	*buffer; // Static buffer to store leftover data between calls
	char		*line;

	// Check for invalid file descriptor or BUFFER_SIZE
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	// Read from the file and store data in the buffer
	buffer = read_file(fd, buffer);
	// If nothing is read, return NULL
	if (!buffer)
		return (NULL);
	// Extract the current line from the buffer
	line = ft_line(buffer);
	// Update the buffer to contain the remaining data
	buffer = ft_next(buffer);
	// Return the extracted line
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main() {
    int fd;
    char *line;

    // Open a test file (replace "test.txt" with your actual test file path)
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return (1);
    }

    // Read lines using get_next_line
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line: %s", line); // Print each line
        free(line); // Free the memory allocated for the line
    }

    // Close the file when done
    close(fd);
    return (0);
}
