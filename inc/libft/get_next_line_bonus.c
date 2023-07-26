/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:01:07 by mtrautne          #+#    #+#             */
/*   Updated: 2022/12/15 19:30:36 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*GNL_FUNCTION AND READ_FUNCTION:
get_next_line:
Input: A file descriptor, pointing to a text file or stdinput (fd = 0).
Task: Repeated calls read the text file pointed to by the file descriptor, one
line at a time and return the line that was read. If an error occurred or there
is nothing else to read, NULL is returned.
Return Value: he line that was read. If an error occurred or there
is nothing else to read, NULL is returned.

ft_resize_static_str:
Input: static_str.
Task: Reads through static_str until it finds a '\n' or '\0'. Creates a 
temporary string containing the characters after the breakpoint, or frees the
static string in case it encounters a '\0'.
Return Value: A partial string of static_str, including all characters after
the first '\n' or NULL if '\0' is encountered.*/

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_str[10300];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_str[fd] = ft_read(fd, static_str[fd]);
	if (!static_str[fd])
		return (NULL);
	line = ft_next_line(static_str[fd]);
	static_str[fd] = ft_resize_static_str(static_str[fd]);
	return (line);
}

char	*ft_read(int fd, char *static_str)
{
	char	*temp;
	int		bytes_read;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr(static_str, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		static_str = ft_strjoin(static_str, temp);
	}
	free(temp);
	return (static_str);
}

char	*ft_resize_static_str(char *static_str)
{
	char	*temp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (static_str[i] && static_str[i] != '\n')
		i++;
	if (static_str[i] == '\0')
	{
		free(static_str);
		return (NULL);
	}
	temp = (char *)malloc((ft_strlen(static_str) - i) * sizeof(char));
	if (!temp)
		return (NULL);
	i++;
	while (static_str[i])
		temp[k++] = static_str[i++];
	temp[k] = '\0';
	free(static_str);
	return (temp);
}
