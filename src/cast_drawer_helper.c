/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_drawer_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:19:31 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/07 23:20:58 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

void	draw_scope(t_vars *vrs)
{
	int	x;
	int	y;

	x = (int)(vrs->win_width / 2);
	y = (int)((vrs->win_height / 2) - 10);
	while (y < ((vrs->win_height / 2) + 10))
	{
		print_pixel(x, y, vrs, 0x0039FF14);
		y++;
	}
	x = (int)((vrs->win_width / 2) - 10);
	y = (int)(vrs->win_height / 2);
	while (x < ((vrs->win_width / 2) + 10))
	{
		print_pixel(x, y, vrs, 0x0039FF14);
		x++;
	}
}
