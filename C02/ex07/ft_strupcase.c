/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:55:20 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/03 00:24:15 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*origin_str;

	origin_str = str;
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z'))
			*str -= 32;
		str++;
	}
	return (origin_str);
}
