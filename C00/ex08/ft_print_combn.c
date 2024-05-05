/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:04:23 by eonoh             #+#    #+#             */
/*   Updated: 2023/11/30 01:14:39 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursive_combn(char *arr, int n, int index, char value)
{
	if (index == n)
	{
		write(1, arr, n);
		if (n + arr[0] - '0' != 10)
			write(1, ", ", 2);
		return ;
	}
	while (value <= '9')
	{
		arr[index] = value;
		recursive_combn(arr, n, index + 1, value + 1);
		value++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	recursive_combn(arr, n, 0, '0');
}
