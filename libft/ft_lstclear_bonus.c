/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:59:51 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:26:31 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Clears the list by deleting all its elements using the 'del' function.
 * It frees the memory allocated for each element and sets the list pointer to NULL.
 * @param lst Pointer to the pointer of the first element of the list.
 * @param del Pointer to the function used to delete the content of each element.
 * @return VOID.
 * ? Example:
 * * If you have a list with elements and you want to clear it,
 * * you can call `ft_lstclear(&my_list, my_del_function);`
 * * After calling this function, 'my_list' will be NULL and all elements will be deleted.
 * ! Note: The 'del' function should handle the freeing of the content of each element.
 * ! If 'del' is NULL, the content will not be freed, but the list will still be cleared.
 * ! This function does not free the list itself, only the elements within it.
 */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
