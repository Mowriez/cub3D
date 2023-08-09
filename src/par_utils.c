/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:34:36 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/07 23:21:28 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	*ft_realloc(void *ptr, size_t orig_len, size_t new_len)
{
	void	*new_ptr;

	if (new_len == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (malloc(new_len));
	else if (new_len <= orig_len)
		return (ptr);
	else
	{
		new_ptr = malloc(new_len);
		if (new_ptr)
		{
			ft_memcpy(new_ptr, ptr, orig_len);
			free(ptr);
		}
		else
			ft_custom_exit("malloc failed");
		return (new_ptr);
	}
}

char	*parse_next_line(int fd)
{
	char		*line;
	static char	*static_str[10300];
	size_t		len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_str[fd] = ft_read(fd, static_str[fd]);
	if (!static_str[fd])
		return (NULL);
	line = ft_next_line(static_str[fd]);
	static_str[fd] = ft_resize_static_str(static_str[fd]);
	if (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
	}
	return (line);
}
