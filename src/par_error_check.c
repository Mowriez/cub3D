/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:04:41 by mwagner           #+#    #+#             */
/*   Updated: 2023/08/09 23:08:47 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

bool	ft_valid_file_ending(const char *filename, char *expected_end)
{
	const char	*file_end = filename + ft_strlen(filename)
		- ft_strlen(expected_end);

	return (ft_strcmp(file_end, expected_end) == 0);
}

bool	ft_texture_exists(const char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (true);
	}
	else
		return (false);
}

bool	ft_check_tex_exist(const char *tex_location)
{
	if (ft_texture_exists(tex_location))
		return (true);
	else
	{
		err_msg("Can't open texture: Check map identifiers");
		return (false);
	}
}

bool	ft_check_all_tex(t_map *map)
{
	bool	all_tex_exist;

	all_tex_exist = true;
	all_tex_exist &= ft_check_tex_exist(map->texture_no);
	all_tex_exist &= ft_check_tex_exist(map->texture_so);
	all_tex_exist &= ft_check_tex_exist(map->texture_we);
	all_tex_exist &= ft_check_tex_exist(map->texture_ea);
	return (all_tex_exist);
}
