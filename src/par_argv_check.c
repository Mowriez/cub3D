/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_argv_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:32:22 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 18:03:30 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

int	check_input(int argc, char**argv)
{
	const char	*map_filename = argv[1];

	if (argc != 2)
		return (err_msg("Incorrect number of arguments\n"));
	if (!ft_valid_file_ending(map_filename, ".cub"))
		return (err_msg("Invalid file ending. Please provide a .cub file.\n"));
	return (0);
}
