/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:25:20 by oait-si-          #+#    #+#             */
/*   Updated: 2024/12/02 10:55:22 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * ft_strjoin - Joins two strings into a new dynamically allocated string.
 * @s1: First string.
 * @s2: Second string.
 * 
 * Allocates memory to combine s1 and s2 into a single string.
 * Returns the newly created string, or NULL if allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	// Calculate total length of the new string
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	// Allocate memory for the result
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	// Copy characters from s1 to res
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	// Copy characters from s2 to res
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	// Null-terminate the new string
	res[sizetotal] = 0;
	return (res);
}

/**
 * ft_strchr - Finds the first occurrence of a character in a string.
 * @string: The string to search.
 * @searchedChar: The character to search for.
 * 
 * Returns a pointer to the first occurrence of searchedChar in string,
 * or NULL if the character is not found.
 */
char	*ft_strchr(const char *string, int searchedChar)
{
    // Traverse the string until the character is found or end of string is reached
    while (*string != searchedChar && *string != '\0')
        string++;
    // Return a pointer to the character if found, or NULL otherwise
    if (*string == searchedChar)
        return (char *)string; 
    else
        return (NULL);
}

/**
 * ft_bzero - Sets a block of memory to zero.
 * @s: Pointer to the memory block.
 * @n: Number of bytes to set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	// Set each byte in the block to '\0'
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/**
 * ft_calloc - Allocates and zeroes a block of memory.
 * @elementCount: Number of elements.
 * @elementSize: Size of each element in bytes.
 * 
 * Allocates memory for an array of elementCount elements, each of elementSize bytes,
 * and initializes the memory to zero.
 * Returns a pointer to the allocated memory, or NULL if allocation fails.
 */
void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;

	// Allocate memory for the array
	res = malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	// Zero out the allocated memory
	ft_bzero(res, elementSize * elementCount);
	return (res);
}

/**
 * ft_strlen - Calculates the length of a string.
 * @theString: The string to measure.
 * 
 * Returns the number of characters in the string, not including the null terminator.
 */
size_t	ft_strlen(const char *theString)
{
	size_t	i;

	i = 0;
	// Count characters until the null terminator is reached
	while (theString[i])
		i++;
	return (i);
}
