/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:15:06 by mivendit          #+#    #+#             */
/*   Updated: 2023/01/27 15:15:07 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = (char *)s;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *) &str[i]);
		i--;
	}
	return (NULL);
}
