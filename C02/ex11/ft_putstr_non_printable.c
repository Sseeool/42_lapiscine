/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:56:56 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/05 03:43:49 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char *str)
{
	write(1, "\\", 1);
	write(1, &"0123456789abcdef"[(unsigned char)*str / 16], 1);
	write(1, &"0123456789abcdef"[(unsigned char)*str % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
			print_hex(str);
		str++;
	}
}
