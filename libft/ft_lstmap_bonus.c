/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:11:08 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:46:19 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Maps the content of each element in the list using the function 'f',
 * creating a new list with the results.
 * If the allocation fails, it clears the new list using 'del'.
 * @param lst Pointer to the first element of the list.
 * @param f Pointer to the function to be applied to each element's content.
 * @param del Pointer to the function used to delete the content of each element if the alloc fails.
 * @return Pointer to the new list with the mapped content,
 * @return or NULL if the allocation fails.
 * ? Example:
 * * If you have a list of integers and you want to double each integer,
 * * you can call `ft_lstmap(my_list, double_function, free_function);
 * * After calling this function, a new list will be created with the doubled integers.
 * * If the allocation fails, the new list will be cleared using 'del'.
 * ! Note: The function 'f' should return a new content for each element,
 * ! and the function 'del' should handle the freeing of the content of each element
 * ! if the allocation fails. If 'del' is NULL, the content will not be freed,
 * ! but the new list will still be created with the mapped content.
 * ! This function does not modify the original list, it creates a new list with the mapped content.
 * ? Example Main Usage:
 * * Example function to double the content
 * * void	*double_function(void *content)
 * * {
 * *     int *new_content = malloc(sizeof(int));
 * *     if (!new_content)
 * *         return NULL; // Allocation failed
 * *     *new_content = *((int *)content) * 2; // Assuming content is
 * *     return new_content; // Return the new content
 * * }
 *
 * * * t_list *my_list = ft_lstnew(malloc(sizeof(int))); // Create a new list with an integer
 * * * (int *)my_list->content = 5; // Set the content to 5
 * * * t_list *new_list = ft_lstmap(my_list, double_function, free_function);
 * * * if (new_list){...}
 * 
 * ! After this, new_list will contain the doubled value (10) if the allocation succeeded.
 * ! If the allocation failed, new_list will be NULL and the original list will remain unchanged.
 * ! Note: The caller is responsible for freeing the new list and its content when no longer needed.
 * ! The original list remains unchanged.
 */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*returnlist;
	void	*newcontent;
	t_list	*newnode;

	returnlist = NULL;
	while (lst)
	{
		newcontent = f(lst->content);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			if (del)
				del(newcontent);
			ft_lstclear(&returnlist, del);
			return (NULL);
		}
		ft_lstadd_back(&returnlist, newnode);
		lst = lst->next;
	}
	return (returnlist);
}
