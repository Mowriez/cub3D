/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:48:03 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/27 00:59:40 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// System Headers
#include <math.h>
#include <stdio.h>

// Project specific headers
#include "colors.h"
#include "./libft/libft.h"

// OS specific Headers
#ifdef __linux__
# include "./mlx/minilibx-linux/mlx.h"

#elif defined(__APPLE__)
# include "./mlx/minilibx_opengl_20191021/mlx.h"

#else
# error "Unsupported operating system"
# endif

#endif
