/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_timing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:14:02 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/07 23:21:14 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"
#include <sys/time.h>

static void	count_fps(t_vars *vrs)
{
	struct timeval	s_cur_time;
	long long		time_sec;

	gettimeofday(&s_cur_time, NULL);
	vrs->ol.cur_time_ms = (s_cur_time.tv_sec * 1000 + s_cur_time.tv_usec
			/ 1000);
	while (vrs->ol.cur_time_ms - vrs->ol.last_loop_time < (1000 / 60))
	{
		gettimeofday(&s_cur_time, NULL);
		vrs->ol.cur_time_ms = (s_cur_time.tv_sec * 1000
				+ s_cur_time.tv_usec / 1000);
		usleep (1000);
	}
	vrs->ol.last_loop_time = vrs->ol.cur_time_ms;
	time_sec = s_cur_time.tv_sec;
	if (time_sec - vrs->ol.last_sec_change == 0)
		vrs->ol.frames++;
	else
	{
		vrs->ol.fps_i = vrs->ol.frames;
		vrs->ol.frames = 0;
		vrs->ol.last_sec_change = time_sec;
	}
}

void	print_fps(t_vars *vrs)
{
	count_fps(vrs);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 15, 60,
		0x0039FF14, "fps counter:");
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 180, 60,
		0x0039FF14, vrs->ol.fps);
}
