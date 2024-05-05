/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:11:35 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/03 15:47:59 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (*src)
	{
		if (len + 1 < size)
			*dest++ = *src;
		src++;
		len++;
	}
	if (size > 0)
		*dest = '\0';
	return (len);
}
