/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:32:22 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/27 18:06:13 by mtrautne         ###   ########.fr       */
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
int	parse_input(int argc, char**argv)
{
	if (argc != 1)
		return (err_msg("incorrect number of arguments"));
	if (argv [1] != NULL)
		return (err_msg("tbd"));
	// if (eval_map())
	// 	return (err_msg("map sucks"));
	return (0);
}