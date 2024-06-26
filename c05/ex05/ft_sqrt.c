/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:38:41 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/12 07:17:03 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb == 1)
		return (1);
	i = 2;
	while (i <= nb / i)
	{
		if (nb / i == i && nb % i == 0)
			return (i);
		i++;
	}
	return (0);
}
