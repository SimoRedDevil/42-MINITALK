/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:59:00 by mel-yous          #+#    #+#             */
/*   Updated: 2022/11/02 18:50:55 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptrsub;
	size_t	i;
	size_t	slen;

	i = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (len > slen || (start + len) > slen)
		len = slen - start;
	if (start >= slen || *s == '\0')
		return (ft_strdup(""));
	ptrsub = (char *)malloc(len + 1);
	if (ptrsub == NULL)
		return (NULL);
	while (i < len)
	{
		ptrsub[i] = s[start + i];
		i++;
	}
	ptrsub[i] = '\0';
	return (ptrsub);
}
