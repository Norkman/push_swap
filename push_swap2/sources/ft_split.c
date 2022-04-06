/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:14:30 by nle-bret          #+#    #+#             */
/*   Updated: 2021/11/30 16:15:50 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_constmat(int word, const char *str, char c)
{
	int		i;
	int		k;
	int		j;
	char	**mat;

	i = 0;
	k = 0;
	j = 0;
	mat = malloc(sizeof(*mat) * (word + 1));
	if (mat == NULL)
		return (NULL);
	mat[word] = NULL;
	while (k < word)
	{
		while (str[i] == c && str[i])
			i++;
		j = i;
		while (str[i] != c && str[i])
			i++;
		mat[k] = ft_substr(str, j, i - j);
		k++;
	}
	return (mat);
}

static int	ft_countword(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**mat;

	if (!s)
		return (NULL);
	mat = NULL;
	word = ft_countword(s, c);
	mat = ft_constmat(word, s, c);
	return (mat);
}
