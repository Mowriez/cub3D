/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_timing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:14:02 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/04 14:01:33 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"
#include <sys/time.h>

static void	count_fps(t_vars *vrs)
{
	struct timeval	s_cur_time;
	double			time_sec;

	gettimeofday(&s_cur_time, NULL);
	time_sec = s_cur_time.tv_sec;
	if (time_sec - vrs->last_sec_change == 0)
		vrs->frames++;
	else
	{
		vrs->fps = vrs->frames;
		vrs->frames = 0;
		vrs->last_sec_change = time_sec;
	}
}

void	print_fps(t_overlay *ol, t_vars *vrs)
{
	count_fps(vrs);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 15, 60,
		0x0039FF14, "fps counter:");
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 180, 60,
		0x0039FF14, ol->fps);
}

// void	limit_fps(t_vars *vrs)
// {
	
// }