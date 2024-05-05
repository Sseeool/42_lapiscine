/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:18:49 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/18 19:47:23 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"
#include "ft_strs_to_tab.c"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		ft_putnbr(nb);
	}
	else if (nb < 10)
		write(1, &"0123456789"[nb], 1);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1,"\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

int main()
{
    char        *strs[] = {"Hello", "World", "C programming", ""};
    t_stock_str *tab;
    // Prepare data for testing ft_strs_to_tab
    int ac = 4; // Number of strings
    tab = ft_strs_to_tab(ac, strs);
    // Manually check each element
    for (int i = 0; i < ac; i++)
    {
        printf("Testing element %d:\n", i);
        printf("Expected size: %lu, Actual size: %d\n", strlen(strs[i]),
            tab[i].size);
        printf("Expected str: %s, Actual str: %s\n", strs[i], tab[i].str);
        printf("Expected copy: %s, Actual copy: %s\n\n", strs[i], tab[i].copy);
    }
    // Test ft_show_tab function - manually verify the output
    printf("Output of ft_show_tab:\n");
    fflush(stdout);
    ft_show_tab(tab);
    // Free allocated memory
    for (int i = 0; i < ac; i++)
    {
        free(tab[i].copy);
    }
    free(tab);
}
