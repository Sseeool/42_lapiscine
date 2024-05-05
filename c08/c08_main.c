/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c08_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhseo <wonhseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:59:17 by wonhseo           #+#    #+#             */
/*   Updated: 2023/12/18 19:23:45 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft.h"
#include "ex01/ft_boolean.h"
#include "ex02/ft_abs.h"
#include "ex03/ft_point.h"
#include "ft_stock_str.h"
#include "ex04/ft_strs_to_tab.c"
#include "ex05/ft_show_tab.c"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

void	test_even_macro(void)
{
	assert(EVEN(2) == TRUE);
	assert(EVEN(3) == FALSE);
}

void	test_abs_macro(void)
{
	assert(ABS(-5) == 5);
	assert(ABS(5) == 5);
	assert(ABS(-INT_MAX) == INT_MAX);
	assert(ABS(INT_MAX) == INT_MAX);
}

void	test_point_struct(void)
{
	t_point	point;

	// Assign values to the point
	point.x = 10;
	point.y = 20;
	// Check if the values are correctly assigned
	assert(point.x == 10);
	assert(point.y == 20);
	// Optionally, print out the values
	printf("Point coordinates: x = %d, y = %d\n", point.x, point.y);
}

void	test_ft_strs_to_tab_and_ft_show_tab(void)
{
	char		*strs[] = {"Hello", "World", "C programming", ""};
	t_stock_str	*tab;

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

int	main(void)
{
	test_even_macro();
	test_abs_macro();
	test_point_struct();
	test_ft_strs_to_tab_and_ft_show_tab();
	printf("All tests passed successfully.\n");
	return (0);
}
