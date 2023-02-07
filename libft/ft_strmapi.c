/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:14:50 by mivendit          #+#    #+#             */
/*   Updated: 2023/02/01 12:11:48 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(result))
		return (NULL);
	i = -1;
	while (*(s + ++i))
		*(result + i) = f(i, *(s + i));
	*(result + i) = '\0';
	return (result);
}

/*char	test(unsigned int i, char c)
{
	return (c + i);
}

int	 main(void)
{
	char	*str;
	str = ft_strmapi("test", &test);
	printf("%s\n", str);
	free(str);
	return (0);
}*/