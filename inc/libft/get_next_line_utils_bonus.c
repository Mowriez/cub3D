/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:40:57 by mtrautne          #+#    #+#             */
/*   Updated: 2022/12/15 19:30:42 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*UTILITIES FOR GNL_FUNCTION:
ft_strlen: 
Added case for !s. Used to check string lenght of various strings.
ft_strjoin: 
Added cass for !s1. As in the first call static_str is not 
allocated, it needs to be created somewhere. Makes sense here as it can be
easily freed.
ft_strchr: 
used to test for '\n' in static_str. Returns a pointer to the address
of the first occurence of '\n', or NULL. In gnl it's only important if it finds
'\n', not where.
ft_next_line:
Input: static_str.
Task: Reads through static_str until it finds a '\n' or '\0'. Creates a 
temporary string containing the characters up to the breakpoint.
Return Value: A partial string of static_str, up to and includeing the first 
'\n' or '\0'.
ft_resize_static_str:
Input: static_str.
Task: Reads through static_str until it finds a '\n' or '\0'. Creates a 
temporary string containing the characters after the breakpoint, or frees the
static string in case it encounters a '\0'.
Return Value: A partial string of static_str, including all characters after
the first '\n' or NULL if '\0' is encountered.*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		l;
	char		*j;

	i = -1;
	l = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	j = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!j)
		return (NULL);
	while (s1[++i])
		j[i] = s1[i];
	while (i < ft_strlen(s1) + ft_strlen(s2) && s2[l])
		j[i++] = s2[l++];
	j[i] = '\0';
	free(s1);
	return (j);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	c = (unsigned char) c;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == '\0' && c != '\0')
		return (NULL);
	return ((char *)s + i);
}

char	*ft_next_line(char *static_str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (!static_str[i])
		return (NULL);
	while (static_str[i] != '\0' && static_str[i] != '\n')
		i++;
	temp = (char *)malloc((i + 2) * sizeof(char));
	if (!temp)
		return (NULL);
	while (static_str[j] != '\0' && static_str[j] != '\n')
	{
		temp[j] = static_str[j];
		j++;
	}
	if (static_str[j] == '\n')
	{
		temp[j] = '\n';
		j++;
	}
	temp[j] = '\0';
	return (temp);
}
