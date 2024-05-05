/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:36:17 by eonoh             #+#    #+#             */
/*   Updated: 2023/11/30 00:36:19 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursive_print(char *arr, int index, char value)
{
	if (index == 3)
	{
		write(1, arr, 3);
		if (arr[0] != '7')
			write(1, ", ", 2);
		return ;
	}
	while (value <= '9')
	{
		arr[index] = value;
		recursive_print(arr, index + 1, value + 1);
		value++;
	}
}

void	ft_print_comb(void)
{
	char	arr[5];

	recursive_print(arr, 0, '0');
}
