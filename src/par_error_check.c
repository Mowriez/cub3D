/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:04:41 by mwagner           #+#    #+#             */
/*   Updated: 2023/08/07 18:05:21 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

bool	ft_valid_file_ending(const char *filename, char *expected_end)
{
	const char	*file_end = filename + ft_strlen(filename)
		- ft_strlen(expected_end);

	return (ft_strcmp(file_end, expected_end) == 0);
}
