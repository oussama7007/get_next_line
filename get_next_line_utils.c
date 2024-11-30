/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:25:20 by oait-si-          #+#    #+#             */
/*   Updated: 2024/11/29 11:27:50 by oait-si-         ###   ########.fr       */
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

static int  ft_strjoin_lenght(char  const *s1, char const   *s2)
{
    size_t  len_s1;
    size_t  len_s2;
    
    len_s1 = 0;
    len_s2 = 0;
    if(s1)
        len_s1 = ft_strlen(s1);
    if(s2)
        len_s2 = ft_strlen(s2);
    return(len_s1 + len_s2); 
}

static void ft_strjoin_contact(char *new, char const *s1, char const *s2)
{
    size_t  i;
    size_t  j;
    
    i = 0;
    if(s1)
    {
        while(s1[i])
        {
            new[i] = s1[i];
            i++;
        }
    }
    j = 0;
    if(s2)
    {
        while(s2[j])
        {
            new[i] = s2[j];
            i++;
            j++;
        }
    }
    new[i] = '\0';
}
 
char    *ft_strjoin(const char *s1, const char *s2)
{
    char    *new;
    int     total_len;

    total_len = ft_strjoin_lenght(s1, s2);
    new = (char *)malloc(sizeof(char)*(total_len +1));
    if(!new)
        return (NULL);
    ft_strjoin_contact(new, s1, s2);
    return(new);
}