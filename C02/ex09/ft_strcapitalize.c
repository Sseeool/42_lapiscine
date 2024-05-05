/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:33:20 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/03 17:00:31 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char *str)
{
	return (*str >= 'a' && *str <= 'z');
}

int	is_uppercase(char *str)
{
	return (*str >= 'A' && *str <= 'Z');
}

int	is_sep(char *str)
{
	return (!((is_lowercase(str) == 1) || (is_uppercase(str) == 1) || \
		(*str >= '0' && *str <= '9')));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i])
	{
		if (flag == 1)
		{
			if (is_lowercase(&str[i]) == 1)
				str[i] -= 32;
			flag = 0;
		}
		else if (flag == 0)
		{
			if (is_uppercase(&str[i]) == 1)
				str[i] += 32;
		}
		if (is_sep(&str[i]) == 1)
			flag = 1;
		i++;
	}
	return (str);
}
