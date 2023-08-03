/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:20:48 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/04 00:01:57 by mtrautne         ###   ########.fr       */
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

int	set_key_status_pressed(int keycode, t_vars *vrs)
{
	printf("%i pressed\n", keycode);
	if (keycode == KEY_W)
		vrs->key_state[0] = KEY_PRESSED;
	else if (keycode == KEY_S)
		vrs->key_state[1] = KEY_PRESSED;
	if (keycode == KEY_A)
		vrs->key_state[2] = KEY_PRESSED;
	else if (keycode == KEY_D)
		vrs->key_state[3] = KEY_PRESSED;
	if (keycode == KEY_LEFT)
		vrs->key_state[4] = KEY_PRESSED;
	else if (keycode == KEY_RIGHT)
		vrs->key_state[5] = KEY_PRESSED;
	return (0);
}

int	set_key_status_free(int keycode, t_vars *vrs)
{
	printf("%i released\n", keycode);
	if (keycode == KEY_W)
		vrs->key_state[0] = KEY_FREE;
	if (keycode == KEY_S)
		vrs->key_state[1] = KEY_FREE;
	if (keycode == KEY_A)
		vrs->key_state[2] = KEY_FREE;
	if (keycode == KEY_D)
		vrs->key_state[3] = KEY_FREE;
	if (keycode == KEY_LEFT)
		vrs->key_state[4] = KEY_FREE;
	if (keycode == KEY_RIGHT)
		vrs->key_state[5] = KEY_FREE;
	if (keycode == KEY_ESC)
		ft_free(vrs);
	if (keycode == KEY_O)
		vrs->overlay = !(vrs->overlay);
	return (0);
}
