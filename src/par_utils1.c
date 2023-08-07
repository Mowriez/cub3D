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

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	free(map->texture_no);
	free(map->texture_so);
	free(map->texture_we);
	free(map->texture_ea);
	if (map->line_array != NULL)
	{
		while (i < map->line_count)
		{
			free(map->line_array[i]);
			i++;
		}
		free(map->line_array);
	}
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

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (ptr == NULL)
		return (malloc(size));
	else if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		if (new_ptr == NULL)
			return (NULL);
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
		return (new_ptr);
	}
}
