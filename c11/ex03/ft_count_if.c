/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 07:00:22 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/21 07:30:33 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	count;

	while (*tab)
	{
		if (f(*tab) != 0)
			count++;
		tab++;
	}
	return (count);
}

int	is_yes(char *str)
{
	return (strcmp(str, "yes") == 0) ? 1 : 0;
}

int main()
{
	char	*arr[] = {"no", "maybe", "no", NULL};
	if (ft_count_if(
}
