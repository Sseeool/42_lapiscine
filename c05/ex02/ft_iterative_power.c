/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:45:59 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/12 05:06:35 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	pow;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 0;
	pow = 1;
	while (i < power)
	{
		pow *= nb;
		i++;
	}
	return (pow);
}
