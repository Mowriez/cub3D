/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:29:28 by mwagner           #+#    #+#             */
/*   Updated: 2023/08/07 19:30:20 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

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
