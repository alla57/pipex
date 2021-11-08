/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:55:08 by alboumed          #+#    #+#             */
/*   Updated: 2021/10/16 14:45:12 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	if (!count || !size)
		return (dest = malloc(count * size));
	dest = (void *)malloc(size * count);
	if (!dest)
		return (NULL);
	return (ft_bzero(dest, count));
}
