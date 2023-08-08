/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:32:22 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/06 11:21:12 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

int	check_input(int argc, char**argv)
{
	const char	*map_filename = argv[1];

	if (argc != 2)
		return (err_msg("incorrect number of arguments\n"));
	if (argv [2] != NULL)
		return (err_msg("tbd"));
	if (!ft_valid_file_ending(map_filename, ".cub"))
		return (err_msg("Invalid file ending. Please provide a .cub file.\n"));
	return (0);
}
