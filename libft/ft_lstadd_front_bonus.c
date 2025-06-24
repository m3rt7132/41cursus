/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:36:54 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:21:22 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Adds the element 'new' at the beginning of the list.
 * If the list is empty, it sets 'new' as the first element.
 * @param lst Pointer to the pointer of the first element of the list.
 * @param new Pointer to the new element to be added.
 * @return VOID.
 */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
