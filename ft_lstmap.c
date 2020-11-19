/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:34:19 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/09 17:40:24 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_lst;
	t_list	*mapped_element;

	mapped_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		mapped_element = ft_lstnew((*f)(lst->content));
		if (!mapped_element)
		{
			ft_lstclear(&mapped_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped_lst, mapped_element);
	}
	return (mapped_lst);
}
