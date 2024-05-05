/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:40:27 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/20 18:21:02 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	contain(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (flag == 1 && contain(*str, charset) == 0)
		{
			count++;
			flag = 0;
		}
		else if (flag == 0 && contain(*str, charset) == 1)
			flag = 1;
		str++;
	}
	return (count);
}

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (*src)
	{
		if (len + 1 < size)
			*dst++ = *src;
		src++;
		len++;
	}
	if (size > 0)
		*dst = '\0';
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	**tokens;
	char	*start;
	int		count;
	int		i;
	int		len;

	count = word_count(str, charset);
	tokens = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*str && contain(*str, charset) == 1)
			str++;
		start = str;
		while (*str && contain(*str, charset) == 0)
			str++;
		len = str - start;
		tokens[i] = (char *)malloc(sizeof(char) * (len + 1));
		ft_strlcpy(tokens[i], start, len + 1);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
