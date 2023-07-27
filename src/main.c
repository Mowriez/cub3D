/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:20:48 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/27 20:27:18 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars	*vrs;

	vrs = NULL;
	if (parse_input(argc, argv))
		return (1);
	if (init_struct(argc, argv, &vrs))
		return (1);
	// if ()
	mlx_loop(vrs->mlx_ptr);
	ft_free(vrs);
	return (0);
}

void	ft_free(t_vars *vrs)
{
	mlx_destroy_image(vrs->mlx_ptr, vrs->img_ptr);
	mlx_destroy_window(vrs->mlx_ptr, vrs->win_ptr);
	free(vrs);
}
