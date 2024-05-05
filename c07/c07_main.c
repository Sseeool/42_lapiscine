/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c07_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonshin <seonshin@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:21:26 by seonshin          #+#    #+#             */
/*   Updated: 2023/12/16 18:09:46 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//#include "ex00/ft_strdup.c"
//#include "ex01/ft_range.c"
//#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
#include "ex04/ft_convert_base.c"
#include "ex04/ft_convert_base2.c"
//#include "ex05/ft_split.c"

/*void	test_ex00( char *src);
void	test_ex01(int min, int max);
void	test_ex02(int min, int max);*/
void	test_ex03(int size, char **strs, char *sep);
void	test_ex04(char *nbr, char *base_from, char *base_to);
//void	test_ex05(char *str, char *charset);

int	main(void)
{
	setbuf(stdout, NULL);
	
/*	printf("========== ex00 ==========\n");

	test_ex00("AsDf");
	test_ex00("ashdfjkwer\tsadhkaasdd");
	test_ex00("ThisIsAwssomeFunction.");

	printf("========== ex01 ==========\n");

	test_ex01(5, 9);
	test_ex01(1004, 1006);
	test_ex01(-103, -100);
	test_ex01(100, 0);
	
	printf("========== ex02 ==========\n");
	
	test_ex02(5, 9);
	test_ex02(1004, 1006);
	test_ex02(-103, -100);
	test_ex02(100, 0);
*/	
	printf("========== ex03 ==========\n");
	
	char	*str031[3] = {"ASDF", "#asdwe#", "!asdwe!"};
	char	*str031s = "***";
	char	*str032[5] = {"HELLO,", "World!", "I", "LOVE", "YOU!"};
	char	*str032s = " ";

	test_ex03(sizeof(str031) / 8, str031, str031s);
	test_ex03(sizeof(str032) / 8, str032, str032s);
	test_ex03(0, str031, str031s);
	
	printf("========== ex04 ==========\n");
	
	test_ex04("2147483647", "0123456789", "0123456789abcdef");
	test_ex04("    -++--2147483648abcdf", "0123456789", "0123456789abcdef");
	test_ex04("\t  \t-+---+-ADDDDDDD0123", "D1234567A9abcdef", "0123456789");
	test_ex04("2147483647", "+-123", "12asd");
	
/*	printf("========== ex05 ==========\n");
	
	test_ex05("Hello World!", " ");
	test_ex05("H ello   Wor ld!", " ");
	test_ex05("abracadabra!!!", "a");
	test_ex05("abacadaeafaga", "a");
	test_ex05("aaaaabaacaadaaeaafaagaa", "aa");
	test_ex05("ABAbABaBABABqwerABsqdeABsqAABABAB", "AB");
	test_ex05("  1234  5678 876   ", " ");
	test_ex05("aBcDeFg", "");
	*/
	return (0);
}

/*void	test_ex00(char *src)
{
	char	*str = ft_strdup(src);
	printf("test (%s) : (%s)\n", src, str);
	free(str);
	str = 0;
	return ;
}

void	test_ex01(int min, int max)
{
	int		idx = 0;
	int		*list = ft_range(min, max);

	printf("test (%d) ~ (%d)\n", min, max);
	if (!list)
		printf("NULL");
	while (idx < max - min)
		printf("(%d) ", list[idx++]);
	printf("\n\n");
	free(list);
	list = 0;
	return ;
}

void	test_ex02(int min, int max)
{
	int		idx = 0;
	int		*tmp = 0;
	int		**list = &tmp;
	int		size = ft_ultimate_range(list, min, max);

	printf("test (%d) ~ (%d)\n", min, max);
	if (!*list)
		printf("NULL");
	while (idx < max - min)
		printf("(%d) ", (*list)[idx++]);
	printf("\nsize is (%d)\n\n", size);
	free(*list);
	*list = 0;
	return ;
}
*/
void	test_ex03(int size, char **strs, char *sep)
{
	char	*result = ft_strjoin(size, strs, sep);
	int		idx = 0;
	while (idx < size)
	{
		printf("str(%d) : (%s)\n", idx, strs[idx]);
		idx++;
	}
	printf("sep : (%s)\n", sep);
	printf("result : (%s)\n\n", result);
	free(result);
	result = 0;
	return ;
}

void	test_ex04(char *nbr, char *base_from, char *base_to)
{
	char	*result = ft_convert_base(nbr, base_from, base_to);

	printf("nbr\t\t: (%s)\n", nbr);
	printf("base_from\t: (%s)\n", base_from);
	printf("base_to\t\t: (%s)\n", base_to);
	printf("nbr\t\t: (%s)\n\n", result);
	return ;
}

/*void	test_ex05(char *str, char *charset)
{
	char	temp = 0;
	char	*tmp = &temp;
	char	**result = &tmp;
	int		idx = 0;

	result = ft_split(str, charset);
	printf("test (%s) and (%s)\n", str, charset);
	while (result[idx] != 0)
	{
		printf("str%d\t: (%s)\n", idx, result[idx]);
		free(result[idx]);
		result[idx] = 0;
		idx++;
	}
	printf("\n");
	free(result);
	result = 0;
	return ;
}*/
