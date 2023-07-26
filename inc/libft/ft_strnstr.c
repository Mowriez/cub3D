/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:17:09 by mtrautne          #+#    #+#             */
/*   Updated: 2022/06/08 07:52:42 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
locates the first occurrence of the null-terminated string needle in the string 
haystack, where not more than len characters are searched. Characters that 
appear after a ‘\0’ character are not searched.

Return value:
If needle is an empty string, haystack is returned; if needle occurs nowhere 
in haystack, NULL is returned; otherwise a pointer to the first character of 
the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	if (!haystack)
		return (0);
	while (haystack[j] && j <= len)
	{
		while (haystack[i + j] && needle[i]
			&& needle[i] == haystack[j + i] && (i + j) < len)
			i++;
		if (ft_strlen(needle) == i)
			return ((char *)haystack + j);
		j++;
		i = 0;
	}
	return (0);
}
