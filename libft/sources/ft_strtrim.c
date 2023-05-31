/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:15:12 by mivendit          #+#    #+#             */
/*   Updated: 2023/02/01 12:21:08 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	if (!s1[0])
		return (ft_strdup(""));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	str = (char *)malloc((j - i + 2) * sizeof(char));
	if (!(str))
		return (NULL);
	k = 0;
	while (i <= j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}

/*int	main(void)
{
	char	*str;
	str = ft_strtrim("  Hello World!  ", " ");
	printf("%s\n", str);
	free(str);
	return (0);
}*/