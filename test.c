#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

// Free memory and reset pointer
static void free_memory(char **ptr)
{
    if (*ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
}

// Find the position of '\n' in a string
static int find_newline(char *str)
{
    int i = 0;

    if (!str)
        return -1;
    while (str[i])
    {
        if (str[i] == '\n')
            return i;
        i++;
    }
    return -1;
}

// Join two strings into one
static char *str_join(char *s1, char *s2)
{
    int len1 = 0, len2 = 0, i = 0;
    char *new_str;

    while (s1 && s1[len1])
        len1++;
    while (s2 && s2[len2])
        len2++;
    new_str = malloc(len1 + len2 + 1);
    if (!new_str)
        return NULL;
    while (s1 && *s1)
        new_str[i++] = *s1++;
    while (s2 && *s2)
        new_str[i++] = *s2++;
    new_str[i] = '\0';
    return new_str;
}

// Extract a single line from a buffer
static char *extract_line(char **buffer)
{
    int newline_pos = find_newline(*buffer);
    char *line;
    char *remaining;

    if (newline_pos == -1) // No newline, return full buffer
    {
        line = *buffer;
        *buffer = NULL;
        return line;
    }
    line = malloc(newline_pos + 2);
    if (!line)
        return NULL;
    for (int i = 0; i <= newline_pos; i++)
        line[i] = (*buffer)[i];
    line[newline_pos + 1] = '\0';
    remaining = str_join(NULL, *buffer + newline_pos + 1);
    free_memory(buffer);
    *buffer = remaining;
    return line;
}

// Main function to get the next line
char *get_next_line(int fd)
{
    static char *buffer;
    char *temp;
    char *line;
    ssize_t bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    temp = malloc(BUFFER_SIZE + 1);
    if (!temp)
        return NULL;
    while (find_newline(buffer) == -1)
    {
        bytes_read = read(fd, temp, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free_memory(&temp);
            if (bytes_read == 0 && buffer)
                return extract_line(&buffer);
            free_memory(&buffer);
            return NULL;
        }
        temp[bytes_read] = '\0';
        buffer = str_join(buffer, temp);
    }
    free_memory(&temp);
    line = extract_line(&buffer);
    return line;
}

 
#include <stdio.h>
#include <fcntl.h>
 
int main(void)
{
    int     fd;
    int     max_iter;
    char    *line;
 
    fd = open("./test.txt", O_RDONLY);
    max_iter = 100;
    while ((line = get_next_line(fd)) && (max_iter-- > 0))
        (printf("<%s>", line), fflush(stdout), free(line));
    close(fd);
}