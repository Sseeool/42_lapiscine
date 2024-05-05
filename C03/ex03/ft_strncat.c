/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:05:28 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/05 22:59:09 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*origin_str;

	i = 0;
	origin_str = dest;
	while (*dest)
		dest++;
	while (i ++ < nb && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (origin_str);
}
