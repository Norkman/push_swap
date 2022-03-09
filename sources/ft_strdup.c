/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:37:57 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/03 13:12:54 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*s_tmp;
	int		i;

	s_tmp = (char *)s;
	str = malloc(sizeof(*str) * (ft_strlen(s_tmp) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (s_tmp)
	{
		while (s_tmp[i])
		{
			str[i] = s_tmp[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
