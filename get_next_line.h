#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* ************************************************************************** */
/* Includes necessary headers for functionality */
/* ************************************************************************** */

# include <limits.h>    // Provides system-dependent constants (e.g., INT_MAX).
# include <stdlib.h>    // Includes malloc, free, and other memory management functions.
# include <sys/types.h> // Defines data types used in system calls.
# include <sys/uio.h>   // Provides read/write vector operations.
# include <unistd.h>    // Declares read, write, and close system calls.

/* ************************************************************************** */
/* Function Prototypes                                                        */
/* ************************************************************************** */

/**
 * get_next_line - Reads a single line from a file descriptor.
 * @fd: File descriptor to read from.
 * 
 * Returns a dynamically allocated string containing the next line.
 */
char	*get_next_line(int fd);

/**
 * ft_strjoin - Joins two strings into a new dynamically allocated string.
 * @s1: First string.
 * @s2: Second string.
 * 
 * Combines s1 and s2 into a single new string.
 * Returns a pointer to the newly allocated string.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * ft_strchr - Finds the first occurrence of a character in a string.
 * @string: String to search.
 * @searchedChar: Character to find.
 * 
 * Returns a pointer to the first occurrence of the character in the string.
 */
char	*ft_strchr(const char *string, int searchedChar);

/**
 * ft_bzero - Sets a block of memory to zero.
 * @s: Pointer to the memory block.
 * @n: Number of bytes to set to zero.
 */
void	ft_bzero(void *s, size_t n);

/**
 * ft_calloc - Allocates and zeroes a block of memory.
 * @elementCount: Number of elements.
 * @elementSize: Size of each element in bytes.
 * 
 * Allocates memory for an array of elementCount elements,
 * each of elementSize bytes, and initializes the memory to zero.
 */
void	*ft_calloc(size_t elementCount, size_t elementSize);

/**
 * ft_strlen - Calculates the length of a string.
 * @theString: The string to measure.
 * 
 * Returns the number of characters in the string,
 * excluding the null terminator.
 */
size_t	ft_strlen(const char *theString);

#endif
