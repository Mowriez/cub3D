/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:20:48 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/07 18:23:35 by mtrautne         ###   ########.fr       */
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
	mlx_hook(vrs->win_ptr, 5, 1L << 2, set_mouse_key_status, vrs);
	mlx_hook(vrs->win_ptr, 3, 1L << 1, set_key_status_free, vrs);
	// mlx_hook(vrs->win_ptr, ON_MOUSEMOVE, 1L << 6, pan_view_mouse, vrs);
	mlx_loop_hook(vrs->mlx_ptr, visualizer, vrs);
	mlx_loop(vrs->mlx_ptr);
	ft_free(vrs);
	return (0);
}

int	ft_free(t_vars *vrs)
{
	int	i;

	i = 0;
	mlx_destroy_image(vrs->mlx_ptr, vrs->main_img.img_ptr);
	mlx_destroy_image(vrs->mlx_ptr, vrs->m_map.img_ptr);
	mlx_destroy_window(vrs->mlx_ptr, vrs->win_ptr);
	while (i <= vrs->map_height)
		free(vrs->map[i++]);
	free(vrs->map);
	free(vrs->key_state);
	free(vrs);
	close(vrs->mapfile_fd);
	exit(1);
}

int	set_mouse_key_status(int keycode, t_vars *vrs)
{
	vrs->mouse_state = 1;
	printf("keycode: %i\n", keycode);
	if (keycode == 1)
		printf("here\n");
	printf("vrs->key_state[6]: %p\n", &vrs->mouse_state);
	return (0);
}

// void	pan_view_mouse(int x, int y, t_vars *vrs)
// {
// 	if (x < (vrs->win_width / 2))
// 	{
// 		vrs->rc->view_angle -= ((0.5 * vrs->win_width) - x) * (0.5 * vrs->rc.fov_angle);
		
// 	}

// }