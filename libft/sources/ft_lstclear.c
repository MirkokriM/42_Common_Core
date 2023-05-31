/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:17:10 by mivendit          #+#    #+#             */
/*   Updated: 2023/02/03 08:17:10 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))

{
	t_list	*tmp;
	t_list	*next;

	if (lst)
	{
		tmp = *lst;
		while (tmp)
		{
			next = tmp->next;
			ft_lstdelone(tmp, (del));
			tmp = next;
		}
		*lst = NULL;
	}
}
