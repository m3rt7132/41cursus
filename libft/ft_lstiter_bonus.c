/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:01:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:28:34 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Iterates through the list and applies the function 'f' to the content of each element.
 * @param lst Pointer to the first element of the list.
 * @param f (void *content) Pointer to the function to be applied to each element's content.
 * @return VOID.
 * ? Example:
 * * If you have a list and you want to apply a function to each element's content
 * * you can call `ft_lstiter(my_list, my_function);`
 * * After calling this function, 'my_function' will be applied to the content of each
 * * element in the list.
 * ! Note: The function 'f' should not modify the list structure, it should only
 * ! operate on the content of each element.
 */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
