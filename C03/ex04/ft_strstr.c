/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:05:46 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/07 00:47:41 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *to_find)
{
	int	len;

	len = 0;
	while (*(to_find + len))
		len++;
	return (len);
}

int	ft_strncmp(char *str, char *to_find, int len)
{
	int	i;

	i = 0;
	while ((*str || *to_find) && i < len)
	{
		if (*str != *to_find)
			return (*str - *to_find);
		i++;
		str++;
		to_find++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	len;
	int	cmp_rslt;

	len = ft_strlen(to_find);
	if (len == 0)
		return (str);
	while (*str)
	{
		if (*str == to_find[0])
		{
			cmp_rslt = ft_strncmp(str, to_find, len);
			if (cmp_rslt == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
