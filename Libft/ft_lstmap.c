/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:49:51 by alboumed          #+#    #+#             */
/*   Updated: 2021/10/16 14:49:36 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;

	if (!lst || !f)
		return (NULL);
	map = ft_lstnew(f(lst->content));
	if (!map)
	{
		ft_lstclear(&map, del);
		return (NULL);
	}
	map->next = ft_lstmap(lst->next, f, del);
	return (map);
}
