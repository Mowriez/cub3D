/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:17:09 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/07 10:45:41 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
allocates sufficient memory for a copy of the string s1, does the copy, and 
returns a pointer to it. The pointer may subsequently be used as an argument 
to the function free(3).

Return value:
returns pointer to allocated memory. If insufficient memory is available, NULL 
is returned and errno is set to ENOMEM.*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*j;

	i = 0;
	j = malloc((ft_strlen(s1) + 1) * sizeof(char));
	while (i < ft_strlen(s1))
	{
		j[i] = s1[i];
		i++;
	}
	j[i] = '\0';
	return (j);
}
