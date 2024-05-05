/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:26:34 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/10 01:08:51 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

void	print(long nbr, char *base, int radix)
{
	if (nbr < radix)
		write(1, &base[nbr], 1);
	else
	{
		print(nbr / radix, base, radix);
		print(nbr % radix, base, radix);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		radix;

	radix = is_valid(base);
	if (radix == 0)
		return ;
	nb = (long)nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	print(nb, base, radix);
}
