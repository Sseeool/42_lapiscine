/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:22:50 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/14 03:24:28 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	size = max - min;
	if (size < 1)
		return (0);
	*range = (int *)malloc(sizeof(int) * (size));
	if (!(*range))
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i++] = min++;
	}
	return (size);
}
