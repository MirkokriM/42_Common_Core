/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:17:30 by mivendit          #+#    #+#             */
/*   Updated: 2023/02/03 08:17:30 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*el;

	el = (t_list *) malloc(sizeof(*el));
	if (!el)
		return (NULL);
	el->content = content;
	el->next = NULL;
	return (el);
}
