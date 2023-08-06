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

// static void	eval_map(void)
// {

// }

/*	FCT:	checks argv for correct input, especially map formatting and
		texture validity;
	ARG:	argv and argc.
	RET:	true (=error) if any error occurs, else false;
*/

static bool	ft_valid_file_ending(const char *filename, char *expected_end)
{
	const char *file_end = filename + ft_strlen(filename) - ft_strlen(expected_end);
	return (ft_strcmp(file_end, expected_end) == 0);
}

int	parse_input(int argc, char**argv)
{
	bool only_valid_chars = false;
	if (argc != 2)
		return (err_msg("incorrect number of arguments\n"));
	if (argv [2] != NULL)
		return (err_msg("tbd"));
	const char *map_filename = argv[1];
	if (!ft_valid_file_ending(map_filename, ".cub"))
		return (err_msg("Invalid file ending. Please provide a .cub file.\n"));
//	only_valid_chars = ft_valid_map_chars(map_filename);
//	if (!only_valid_chars)
//		return (err_msg("Map contains invalid characters!\n"));
	// if (eval_map())
	// 	return (err_msg("map sucks"));
	return (0);
}
