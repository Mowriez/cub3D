/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:17:09 by mtrautne          #+#    #+#             */
/*   Updated: 2022/06/08 22:51:29 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
locates the first occurrence of c (converted to an unsigned char) in string s.

Return value:
returns a pointer to the byte located, or NULL if no such byte exists within 
n bytes.

Crazy Testcases:
if i > 255 one wants to actually typecast it as unsigned char, as otherwise
it will mess up while comparing to s. (i = 't'+255 makes 371 and char 371 is 
god knows what). On the other hand, if i < 0 one does not want that conversion, 
as it looses the '-'.*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*i;
	size_t	j;

	i = (char *)s;
	j = 0;
	if (c > 0)
		c = (unsigned char)c;
	while (j < n)
	{
		if (i[j] == c)
			return ((void *)i + j);
		j++;
	}
	return (0);
}
