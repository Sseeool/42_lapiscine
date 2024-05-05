/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:00:37 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/17 01:42:57 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*arr;
	int	i;

	size = max - min;
	if (size < 1)
		return (0);
	arr = (int *)malloc(sizeof(int) * (size));
	if (arr == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		arr[i++] = min++;
	}
	return (arr);
}
