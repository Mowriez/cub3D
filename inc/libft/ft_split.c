/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:09:20 by mtrautne          #+#    #+#             */
/*   Updated: 2022/12/15 20:13:25 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
Allocates (with malloc(3)) and returns an array of strings obtained by splitting 
’s’ using the character ’c’ as a delimiter. The array must end with a NULL 
pointer.

Return value:
The array of new strings resulting from the split. NULL if the allocation fails.

Parameters:
s: The string to be split. c: The delimiter character.

External functions:
malloc, free

Particularities:
/0 as last string in ret[j]. Dont really know why, but the tester asks for it.
Maybe free all the strings in ret, if malloc-protection triggers? - done.*/

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	word_nbr;
	size_t	switch_fct;
	size_t	i;

	word_nbr = 0;
	switch_fct = 0;
	i = 0;
	if (s[i] && s[i] != c)
		word_nbr = 1;
	while (s[i])
	{
		if (s[i] == c)
			switch_fct = 1;
		else if (s[i] != c && switch_fct == 1)
		{
			word_nbr++;
			switch_fct = 0;
		}
		i++;
	}
	return (word_nbr);
}

static size_t	ft_word_len(char const *s, size_t start, char c)
{
	size_t	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

static char	**ft_free_if_fail(char **ret, size_t j)
{
	while (j != 0)
	{
		free(ret[j]);
		j--;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**ret;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ret = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while (i < ft_strlen(s) && j < ft_word_count(s, c))
	{
		while (s[i] == c)
			i++;
		len = ft_word_len(s, i, c);
		ret[j] = ft_substr(s, i, len);
		if (!(ret[j]))
			return (ft_free_if_fail(ret, j));
		j++;
		i = i + len;
	}
	ret[j] = 0;
	return (ret);
}
