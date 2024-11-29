/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:25:20 by oait-si-          #+#    #+#             */
/*   Updated: 2024/11/29 10:26:33 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t  ft_strlen(char  *s)
{
    size_t  i;
    if(!s)
        return (0);
    while(s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strchr(char *s, int c)
{
    int i;
    i = 0;
    if(!s)
        return NULL; 
    if(c == '\0')
            return((char *)&s(ft_strlen(s)));
    while(s[i])
    {
        if(s[i] == (char)c)
            return((char *)s +i);
        i++;
    }
    return NULL;
}

chat    *ft_strjoin(char *s1, char *s2)
{
    size_t  i;
    size_t  j;
    char    *str;

    if(!s1)
    {
        s1 =(char *)malloc(1 * sizeof(char));
        
    }
}