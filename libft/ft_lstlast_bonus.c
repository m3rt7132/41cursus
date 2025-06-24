/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:51:38 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:29:07 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Finds the last element of the linked list.
 * If the list is empty, it returns NULL.
 * @param lst Pointer to the first element of the list.
 * @return Pointer to the last element of the list, or NULL if the list is empty
 * @return If the list is empty, it returns NULL.
 */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return ((void *)0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
