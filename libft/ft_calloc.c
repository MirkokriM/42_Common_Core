/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:18:51 by mivendit          #+#    #+#             */
/*   Updated: 2023/02/01 11:21:37 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (ptr)
		while (total--)
			*((unsigned char *)ptr + total) = 0;
	return (ptr);
}

/*int main()
{
	int count = 4;
	int size = 4;
	int *ptr;
	ptr = ft_calloc(count, size);
	if (!ptr)
		return (1);
	return (0);
}*/