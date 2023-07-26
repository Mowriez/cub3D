/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:17:09 by mtrautne          #+#    #+#             */
/*   Updated: 2022/12/15 20:15:46 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
returns a pointer to the last occurrence of the character c in the string s.

Return value:
 return a pointer to the matched character or NULL if the character is not 
 found. The terminating null byte is considered part of the string, so that if 
 c is specified as '\0', these functions return a pointer to the terminator.

Other:
The return part can be written way more sophistically with 
if (s[i] == c
	return((char *)(s + i));
return(j)*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*j;

	i = 0;
	j = 0;
	while (c > 255)
		c = c - 256;
	while (s[i])
	{
		if (s[i] == c)
			j = (char *)(s + i);
		i++;
	}
	if (s[i] == '\0' && c != '\0' && j == 0)
		return (0);
	if (s[i] == '\0' && c != '\0')
		return (j);
	return ((char *)(s + i));
}
