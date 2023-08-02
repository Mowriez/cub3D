/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:46:33 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/02 23:32:26 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	pan_view(t_vars *vrs, int keycode)
{
	double	rotSpeed = 0.1;
	if (keycode == KEY_RIGHT)
	{
		vrs->view_angle -= rotSpeed * M_PI;
	}
	if (keycode == KEY_LEFT)
	{
		vrs->view_angle += rotSpeed * M_PI;
	}
	visualize(vrs);
	mlx_put_image_to_window(vrs->mlx_ptr, vrs->win_ptr, vrs->img_ptr, 0, 0);
}

static void move(t_vars *vrs, int keycode)
{
	double	moveSpeed = .5;
	if (keycode == KEY_W)
	{
		// if (vrs->map[(int)(vrs->player_pos_y + sin(vrs->view_angle) * moveSpeed)][(int)(vrs->player_pos_x + cos(vrs->view_angle) * moveSpeed)] == '0')
		if (vrs->ray_dir_ew == 3)
			vrs->player_pos_x += cos(vrs->view_angle) * moveSpeed;
		else if (vrs->ray_dir_ew == 4)
			vrs->player_pos_x -= cos(vrs->view_angle) * moveSpeed;
		if (vrs->ray_dir_ns == 1)
			vrs->player_pos_y -= sin(vrs->view_angle) * moveSpeed;
		else if (vrs->ray_dir_ns == 2)
			vrs->player_pos_y += sin(vrs->view_angle) * moveSpeed;
	}
	else if (keycode == KEY_S)
	{
		// if (vrs->map[(int)(vrs->player_pos_y - sin(vrs->view_angle) * moveSpeed)][(int)(vrs->player_pos_x - cos(vrs->view_angle) * moveSpeed)] == '0')
		if (vrs->ray_dir_ew == 3)
			vrs->player_pos_x -= cos(vrs->view_angle) * moveSpeed;
		else if (vrs->ray_dir_ew == 4)
			vrs->player_pos_x += cos(vrs->view_angle) * moveSpeed;
		if (vrs->ray_dir_ns == 1)
			vrs->player_pos_y += sin(vrs->view_angle) * moveSpeed;
		else if (vrs->ray_dir_ns == 2)
			vrs->player_pos_y -= sin(vrs->view_angle) * moveSpeed;
	}
	visualize(vrs);
	mlx_put_image_to_window(vrs->mlx_ptr, vrs->win_ptr, vrs->img_ptr, 0, 0);
}

int	keyboard_input(int keycode, t_vars *vrs)
{	
	printf("keycode: %i\n", keycode);
	if ((keycode >= KEY_LEFT && keycode <= KEY_UP))
		pan_view(vrs, keycode);
	if (keycode >= KEY_A && keycode <= KEY_W)
		move(vrs, keycode);
	if (keycode == KEY_ESC)
		ft_free(vrs);
	return (0);
}