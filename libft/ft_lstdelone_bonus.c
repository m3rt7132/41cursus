/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:06:34 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:26:47 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Deletes a node from the linked list.
 * It frees the memory allocated for the node and calls the 'del' function
 * to free the content of the node.
 * @param lst Pointer to the node to be deleted.
 * @param del Pointer to the function used to delete the content of the node.
 * @return VOID.
 * ? Example:
 * * If you have a node and you want to delete it,
 * * you can call `ft_lstdelone(my_node, my_del_function);`
 * * After calling this function, the node will be freed and its content will be deleted.
 * ! Note: The 'del' function should handle the freeing of the content of the node.
 * ! If 'del' is NULL, the content will not be freed, but the node will still be deleted.
 * ! This function does not delete the entire list, only the specified node.
 */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
