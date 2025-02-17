/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:33:35 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/21 18:04:51 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*curr;

	if (!lst || !del)
		return ;
	curr = *lst;
	while (curr)
	{
		tmp = curr->next;
		del(curr->content);
		free(curr);
		curr = tmp;
	}
	*lst = NULL;
}
