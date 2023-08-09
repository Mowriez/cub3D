/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_utils1.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:09:16 by mwagner           #+#    #+#             */
/*   Updated: 2023/08/06 13:09:17 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	print_err_msg(int error)
{
	if (error == 1)
		err_msg("Invalid ceiling color");
	else if (error == 2)
		printf("Invalid floor color");
	else if (error == 3)
		printf("Invalid line in map");
}

int	ft_free_map_identifiers(t_map *map)
{
	int	i;

	i = 0;
	if (map->err)
		print_err_msg(map->err);
	else
		err_msg("Some map identifiers are missing or invalid");
	if (map->texture_no != NULL)
		free(map->texture_no);
	if (map->texture_so != NULL)
		free(map->texture_so);
	if (map->texture_we != NULL)
		free(map->texture_we);
	if (map->texture_ea != NULL)
		free(map->texture_ea);
	if (map->line_array != NULL)
	{
		while (i < map->line_count)
			free(map->line_array[i++]);
		free(map->line_array);
	}
	return (1);
}

int	ft_free_map_array(t_map *map)
{
	int	i;

	i = 0;
	err_msg("invalid line in mapfile");
	if (map->texture_no != NULL)
		free(map->texture_no);
	if (map->texture_so != NULL)
		free(map->texture_so);
	if (map->texture_we != NULL)
		free(map->texture_we);
	if (map->texture_ea != NULL)
		free(map->texture_ea);
	if (map->line_array != NULL)
	{
		while (i < map->line_count)
			free(map->line_array[i++]);
		free(map->line_array);
	}
	ft_free_char_array(map->map);
	return (1);
}

int	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->texture_no != NULL)
		free(map->texture_no);
	if (map->texture_so != NULL)
		free(map->texture_so);
	if (map->texture_we != NULL)
		free(map->texture_we);
	if (map->texture_ea != NULL)
		free(map->texture_ea);
	if (map->line_array != NULL)
	{
		while (i < map->line_count)
			free(map->line_array[i++]);
		free(map->line_array);
	}
	ft_free_char_array(map->map);
	return (1);
}

void	ft_free_char_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
