/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:25:35 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/10 01:16:42 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	if (nb >= 2)
	{
		while (i <= (nb / 2))
		{
			if (!(nb % i))
				return (0);
			i++;
		}
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	if (nb >= 2)
	{
		while (1)
		{
			if (ft_is_prime(nb) == 1)
				break ;
			nb++;
		}
	}
	return (nb);
}
