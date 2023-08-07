/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:34:36 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/06 11:21:28 by mwagner          ###   ########.fr       */
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

int	ft_skip_spaces(const char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ')
		i++;
	return (i);
}

// not required atm, since new map parsing needed
static bool	ft_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W');
}

bool	ft_valid_map_chars(const char *filename)
{
	int		fd;
	char	buffer[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (false);
	}
	while (read(fd, buffer, sizeof(buffer)))
	{
		if (buffer[0] != '\n' && !ft_valid_char(buffer[0]))
		{
			close(fd);
			return (false);
		}
	}
	close(fd);
	return (true);
}
