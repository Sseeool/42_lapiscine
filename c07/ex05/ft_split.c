/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:46:27 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/16 23:33:23 by eonoh            ###   ########.fr       */
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

int	count_word(char *str, char *charset)
{
	int	flag;
	int	count;

	flag = 1;
	count = 0;
	while (*str)
	{
		if (flag == 1 && contain(*str, charset) == 0)
		{
			count++;
			flag = 0;
		}
		else if (contain(*str, charset) == 1)
			flag = 1;
		str++;
	}
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*src)
	{
		if (i + 1 < size)
			*dest++ = *src;
		src++;
		i++;
	}
	if (size > 0)
		*dest = '\0';
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**tokens;
	char	*start;
	int		word_count;
	int		len;
	int		i;

	word_count = count_word(str, charset);
	tokens = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!tokens)
		return (NULL);
	i = -1;
	while (++i < word_count)
	{
		while (contain(*str, charset) == 1)
			str++;
		start = str;
		while (*str && contain(*str, charset) == 0)
			str++;
		len = str - start;
		tokens[i] = (char *)malloc(sizeof(char) * (len + 1));
		ft_strlcpy(tokens[i], start, len + 1);
	}
	tokens[i] = NULL;
	return (tokens);
}
