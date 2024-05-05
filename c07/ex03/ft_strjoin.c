/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:46:29 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/19 01:11:56 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*origin_str;

	origin_str = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (origin_str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*newstr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	if (size > 0)
		len += ft_strlen(sep) * (size - 1);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (0);
	newstr[0] = '\0';
	i = 0;
	while (i < size)
	{
		newstr = ft_strcat(newstr, strs[i]);
		if (i != size - 1)
			newstr = ft_strcat(newstr, sep);
		i++;
	}
	return (newstr);
}
