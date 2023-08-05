/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:20:48 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/05 20:00:13 by mtrautne         ###   ########.fr       */
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
	mlx_hook(vrs->win_ptr, 2, 1L << 0, set_key_status_pressed, vrs);
	mlx_hook(vrs->win_ptr, 17, 0L, ft_free, vrs);
	mlx_hook(vrs->win_ptr, 3, 1L << 1, set_key_status_free, vrs);
	mlx_loop_hook(vrs->mlx_ptr, visualizer, vrs);
	mlx_loop(vrs->mlx_ptr);
	ft_free(vrs);
	return (0);
}

int	ft_free(t_vars *vrs)
{
	int	i;

	i = 0;
	mlx_destroy_image(vrs->mlx_ptr, vrs->img_ptr);
	mlx_destroy_window(vrs->mlx_ptr, vrs->win_ptr);
	while (i <= vrs->map_height)
		free(vrs->map[i++]);
	free(vrs->map);
	free(vrs);
	close(vrs->mapfile_fd);
	exit(1);
}
