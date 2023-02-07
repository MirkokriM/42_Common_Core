/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:12:26 by mivendit          #+#    #+#             */
/*   Updated: 2023/02/01 15:32:20 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	if (ft_strlen(s) - (size_t)start < len)
		len = ft_strlen(s) - (size_t)start;
	if (ft_strlen(s) <= (size_t)start || !len)
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = -1;
	while (++i < len && s[(size_t)start + i])
		sub[i] = s[(size_t)start + i];
	sub[i] = '\0';
	return (sub);
}
