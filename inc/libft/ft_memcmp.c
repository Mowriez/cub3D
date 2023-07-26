/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:17:09 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/07 10:34:48 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
compares byte string s1 against byte string s2. Both strings are assumed to be 
n bytes long.

Return value:
returns zero if the two strings are identical, otherwise returns the difference
between the first two differing bytes (treated as unsigned char values, so that
`\200' is greater than `\0', for example).  Zero-length strings are always 
identical.*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*i;
	char	*j;
	size_t	k;

	i = (char *)s1;
	j = (char *)s2;
	k = 0;
	if (i == j)
		return (0);
	while (i && j && k < n)
	{
		if (i[k] != j[k])
			return ((unsigned char)i[k] - (unsigned char)j[k]);
		else
			k++;
	}
	return (0);
}
