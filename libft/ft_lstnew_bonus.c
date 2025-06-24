/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:27:00 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:37:40 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Creates a new list element with the given content.
 * The new element's 'next' pointer is set to NULL.
 * @param content The content to be stored in the new element.
 * @return Pointer to the new element, or NULL if the allocation fails.
 * @return If the allocation fails, it returns NULL.
 * @return If the content is NULL, it still creates a new element with NULL content.
 */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = (t_list *) malloc(sizeof(t_list));
	if (!newlist)
		return ((void *)0);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
