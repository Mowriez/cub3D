/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:46:33 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/02 23:54:31 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	pan_view(t_vars *vrs, int keycode)
{
	double	rotSpeed = 0.1;
	if (keycode == KEY_RIGHT)
	{
		vrs->view_angle += rotSpeed * M_PI;
	}
	else if (keycode == KEY_LEFT)
	{
		vrs->view_angle -= rotSpeed * M_PI;
	}
}

static void move(t_vars *vrs, int keycode)
{
	double	moveSpeed = .5;
	if (keycode == KEY_W)
	{
		// if (vrs->map[(int)(vrs->player_pos_y + sin(vrs->view_angle) * moveSpeed)][(int)(vrs->player_pos_x + cos(vrs->view_angle) * moveSpeed)] == '0')
		vrs->player_pos_x += cos(vrs->view_angle) * moveSpeed;
		vrs->player_pos_y += sin(vrs->view_angle) * moveSpeed;
	}
	else if (keycode == KEY_S)
	{
		// if (vrs->map[(int)(vrs->player_pos_y - sin(vrs->view_angle) * moveSpeed)][(int)(vrs->player_pos_x - cos(vrs->view_angle) * moveSpeed)] == '0')
		vrs->player_pos_x -= cos(vrs->view_angle) * moveSpeed;
		vrs->player_pos_y -= sin(vrs->view_angle) * moveSpeed;
	}
}

int	keyboard_input(int keycode, t_vars *vrs)
{	
	printf("keycode: %i\n", keycode);
	if ((keycode >= KEY_LEFT && keycode <= KEY_DOWN))
		pan_view(vrs, keycode);
	if (keycode >= KEY_A && keycode <= KEY_W)
		move(vrs, keycode);
	if (keycode == KEY_ESC)
		ft_free(vrs);
	visualize(vrs);
	mlx_put_image_to_window(vrs->mlx_ptr, vrs->win_ptr, vrs->img_ptr, 0, 0);
	return (0);
}