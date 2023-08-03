/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_macros.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:20:43 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 18:49:34 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMACROS_H
# define KEYMACROS_H

# define DIR_NORTH 1
# define DIR_SOUTH 2
# define DIR_EAST 3
# define DIR_WEST 4

# define FACING_NORTH 1
# define FACING_SOUTH 2
# define FACING_EAST 3
# define FACING_WEST 4

// mouse and keyboard key representations, possibly only valid for macOS?
#ifdef __linux__
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_O 111


#elif defined(__APPLE__)
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_O 31
// # define KEY_R

#else
# error "Unsupported operating system"
# endif
#endif
