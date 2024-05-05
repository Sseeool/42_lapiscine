/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:16:09 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/18 19:47:49 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*newstr;
	int		len;
	int		i;

	len = ft_strlen(src);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (0);
	i = 0;
	while (src[i])
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

/*struct	s_stock_str *ft_strs_to_tab(int argc, char **argv)
{
	t_stock_str	*dup;
	int		i;

	dup = malloc(sizeof(t_stock_str) * (argc + 1));
	i = 0;
	while (i < argc)
	{
		(dup + i)->size = ft_strlen(argv[i]);
		(dup + i)->str = argv[i];
		(dup + i)->copy = ft_strdup(dup[i].str);
		i++;
	}
	(dup + i)->size = 0;
	(dup + i)->str = 0;
	(dup + i)->copy = 0;
	return (dup);
}*/

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    int i;
    t_stock_str *array;
    array = (t_stock_str *)malloc(sizeof(t_stock_str)* (ac + 1));
    if (!array)
        return (0);
    i = 0;
    while (i < ac)
    {
        array[i].size = ft_strlen(av[i]);
        array[i].str = av[i];
        array[i].copy = ft_strdup(av[i]);
        i++;
    }
    array[i].size = 0;
    array[i].copy = 0;
    return (array);
}
