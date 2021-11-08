/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:03:39 by alboumed          #+#    #+#             */
/*   Updated: 2021/10/28 21:56:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

const char	*next_str(const char *str, char c)
{
	int			i;
	const char	*s;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] == c)
		i++;
	while (str[i] && str[i] != c)
		++i;
	while (str[i] == c)
		++i;
	s = str + i;
	return (s);
}

void	strcpy_until_c(const char *src, char *dest, char c)
{
	int	i;
	int	j;

	if (!src || !dest)
		return ;
	i = 0;
	while (src[i] == c)
		++i;
	j = 0;
	while (src[i] && src[i] != c)
		dest[j++] = src[i++];
	dest[j] = '\0';
}

int	word_len(const char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == c)
		++i;
	len = 0;
	while (str[i] && str[i] != c)
	{
		++len;
		++i;
	}
	return (len);
}

int	count_words(const char *str, char c)
{
	int	i;
	int	words;

	if (!str)
		return (0);
	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c)
			++words;
		while (str[i] && str[i] != c)
			++i;
		while (str[i] == c)
			++i;
	}
	return (words);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	char	**dest;
	int		len;

	dest = malloc (sizeof(char *) * (count_words(str, c) + 1));
	if (!dest)
		return (NULL);
	i = -1;
	len = word_len(str, c);
	while (len)
	{
		dest[++i] = malloc(sizeof(char) * (len + 1));
		strcpy_until_c(str, dest[i], c);
		str = next_str(str, c);
		len = word_len(str, c);
	}
	dest[++i] = NULL;
	return (dest);
}
