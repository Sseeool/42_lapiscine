/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:17:27 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/05 01:28:11 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr_hex(unsigned long a)
{
	char	arr[17];
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
		arr[i++] = '0';
	i--;
	while (a > 0)
	{
		arr[i--] = hex[a % 16];
		a /= 16;
	}
	i = 0;
	while (i < 16)
		write(1, &arr[i++], 1);
}

void	print_char_hex(unsigned char *addr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		write(1, " ", 1);
		j = 0;
		while (j < 2)
		{
			if (len > 0)
			{
				write(1, &"0123456789abcdef"[*addr / 16], 1);
				write(1, &"0123456789abcdef"[*addr % 16], 1);
			}
			else
				write(1, "  ", 2);
			addr++;
			len--;
			j++;
		}
		i++;
	}
}

void	print_char(unsigned char *addr, unsigned int *len)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if ((*len) == 0)
			break ;
		if (*addr >= 32 && *addr <= 126)
			write(1, addr, 1);
		else
			write(1, ".", 1);
		addr++;
		i++;
		(*len)--;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	if (size == 0)
		return (addr);
	i = 0;
	len = size;
	while (i ++ <= size / 16)
	{
		print_addr_hex((unsigned long)addr);
		write(1, ":", 1);
		print_char_hex((unsigned char *)addr, len);
		write(1, " ", 1);
		print_char((unsigned char *)addr, &len);
		write(1, "\n", 1);
		addr += 16;
	}
	return (addr);
}
