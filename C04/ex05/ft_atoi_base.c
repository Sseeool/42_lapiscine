/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:38:39 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/10 01:18:29 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32 || \
			base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

int	check_index(char *base, char c)
{
	int	i;

	i = 0;
	while (*(base + i))
	{
		if (*(base + i) == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base, int radix)
{
	int	n;
	int	i;
	int	sign;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	i = check_index(base, *str);
	while (i != -1)
	{
		n = n * radix + i;
		str++;
		i = check_index(base, *str);
	}
	return (sign * n);
}

int	ft_atoi_base(char *str, char *base)
{
	int	radix;
	int	n;

	radix = is_valid(base);
	if (radix == 0)
		return (0);
	n = ft_atoi(str, base, radix);
	return (n);
}
