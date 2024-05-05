/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:43:31 by eonoh             #+#    #+#             */
/*   Updated: 2023/12/12 04:47:18 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_condition(char *board, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (board[y] == board[i])
			return (0);
		if (y - i == board[y] - board[i])
			return (0);
		if (y - i == -board[y] + board[i])
			return (0);
		i++;
	}
	return (1);
}

void	recursive_ten_queen(char *board, int *cnt, int x, int y)
{
	if (y == 10)
	{
		write(1, board, 10);
		write(1, "\n", 1);
		(*cnt)++;
		return ;
	}
	while (x < 10)
	{
		board[y] = x + '0';
		if (check_condition(board, y) == 1)
			recursive_ten_queen(board, cnt, 0, y +1);
		x++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		i;
	int		cnt;

	cnt = 0;
	i = 0;
	while (i < 10)
	{
		board[i] = '0';
		i++;
	}
	recursive_ten_queen(board, &cnt, 0, 0);
	return (cnt);
}
