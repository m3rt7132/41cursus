/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:11:08 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/10 17:26:57 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*returnlist;
	void	*newcontent;
	t_list	*newnode;

	returnlist = NULL;
	while (lst)
	{
		newcontent = f(lst->content);
		if (!newcontent)
		{
			ft_lstclear(&returnlist, del);
			return (NULL);
		}
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			del(newcontent);
			ft_lstclear(&returnlist, del);
			return (NULL);
		}
		ft_lstadd_back(&returnlist, newnode);
		lst = lst->next;
	}
	return (returnlist);
} */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*returnlist = NULL;
	void	*newcontent;
	t_list	*newnode;

	while (lst)
	{
		newcontent = f(lst->content);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			del(newcontent);
			ft_lstclear(&returnlist, del);
			return (NULL);
		}
		ft_lstadd_back(&returnlist, newnode);
		lst = lst->next;
	}
	return (returnlist);
}
