/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:21:03 by alboumed          #+#    #+#             */
/*   Updated: 2021/10/16 14:38:16 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	get_index(int n)
{
	int	temp;
	int	i;

	i = 1;
	if (n < 0)
		i++;
	temp = n;
	while (temp)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*s;

	i = get_index(n);
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
		s[0] = '-';
	while (--i >= 0 && n != 0)
	{
		if (n >= 0)
			s[i] = (n % 10) + '0';
		else if (n < 0)
			s[i] = (-n % 10) + '0';
		n = n / 10;
	}
	return (s);
}
