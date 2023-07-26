/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:04:29 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/07 09:38:16 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
Outputs the character ’c’ to the given file descriptor.

Return value: 
None

Parameters:
c: The character to output.
fd: The file descriptor on which to write.

External functions:
write

Particularities:
Intereseting file descriptors - 0: Standard Input, 1: Standard Output, 
2: Standard error.*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
