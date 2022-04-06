/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:41:44 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/03 15:06:22 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_begin(char const *s1, char const *set)
{
	int	i;
	int	len;

	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	ft_end(char const *s1, char const *set, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0 && ft_strchr(set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		begin;
	int		end;

	if (set == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL)
		return (NULL);
	begin = ft_begin(s1, set);
	end = ft_end(s1, set, ft_strlen(s1));
	if (begin > end)
		return (ft_strdup(""));
	str = malloc(sizeof(*str) * (end - begin + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + begin, end - begin + 2);
	return (str);
}
