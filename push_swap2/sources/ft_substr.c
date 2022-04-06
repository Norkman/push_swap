/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:53:46 by nle-bret          #+#    #+#             */
/*   Updated: 2022/01/04 15:24:20 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_of_s;

	if (!s)
		return (NULL);
	len_of_s = ft_strlen(s);
	if (start > len_of_s)
		return (ft_strdup(""));
	if (len <= (unsigned int)len_of_s - start)
		str = malloc(sizeof(*str) * (len + 1));
	else
		str = malloc(sizeof(*str) * (len_of_s - (int)start + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
