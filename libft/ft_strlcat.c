/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:13:30 by mivendit          #+#    #+#             */
/*   Updated: 2023/02/01 15:18:15 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	src_i;
	size_t	dst_i;

	if (!dst && dstsize == 0)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	src_i = 0;
	dst_i = dst_len;
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	while (src[src_i] && (dstsize-- - (dst_len + 1)) > 0)
		dst[dst_i++] = src[src_i++];
	dst[dst_i] = '\0';
	return (dst_len + src_len);
}
