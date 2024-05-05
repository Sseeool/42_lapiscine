/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:31:42 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/21 03:52:42 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_valid(char *base);
int	ft_atoi_base(char *str, char *base);

int	nbr_len(long nb, int i)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		len++;
		nb /= i;
	}
	return (len);
}

void	itoa(char **arr, char *base_to, int len, long nb)
{
	int	i;

	i = is_valid(base_to);
	(*arr)[len--] = '\0';
	if (nb == 0)
		(*arr)[0] = *(base_to);
	else if (nb < 0)
	{
		(*arr)[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		(*arr)[len--] = *(base_to + nb % i);
		nb /= i;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*arr;
	long	nb;
	int		len;
	int		base_from_radix;

	nb = ft_atoi_base(nbr, base_from);
	len = is_valid(base_to);
	base_from_radix = is_valid(base_from);
	if (len == 0 || base_from_radix == 0)
		return (NULL);
	len = nbr_len(nb, len);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	itoa(&arr, base_to, len, nb);
	return (arr);
}

#include <stdio.h>
int	main()
{
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "01"));
	return (0);
}
