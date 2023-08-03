/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:20:43 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 22:52:55 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define IMG_WIDTH 1200

// wall directions
# define FACING_NORTH 1
# define FACING_SOUTH 2
# define FACING_EAST 3
# define FACING_WEST 4

//input key positions
# define KEY_PRESSED 1
# define KEY_FREE 0

// motion speeds
# define MV_SP 0.08
# define ROT_SP 0.01

// key numbers for linux/macOS
# ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_O 111

# elif defined(__APPLE__)
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_O 31

# else
#  error "Unsupported operating system"
# endif

// ascii escape characters for text colors
# define RED "\033[1;31m"
# define GRE "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;34m"
# define PUR "\033[1;35m"
# define CYA "\033[1;36m"
# define WHI "\033[1;37m"
# define RES "\033[0m"

#endif
