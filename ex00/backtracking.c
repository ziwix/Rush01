/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:00:34 by gangouil          #+#    #+#             */
/*   Updated: 2023/08/27 21:33:15 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		backtracking(int ***tab, int x, int y, int i);
int		is_valid(int ***tab, int x, int y, int fixe);
int		end_check(int ***tab, int x, int y);
void	display(int ***tab, int x, int y);
void	mfree(int ***tab, int i, int j);

int	is_valid(int ***tab, int x, int y, int fixe)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < 4)
	{
		if (j != x && tab[j][y][4] == fixe)
			return (0);
		j++;
	}
	while (k < 4)
	{
		if (k != y && tab[x][k][4] == fixe)
			return (0);
		k++;
	}
	return (1);
}

int	backtracking(int ***tab, int x, int y, int i)
{
	i = 0;
	if (y == 4)
		return (1);
	if (tab[x][y][4] != 0 && x != 3)
		return (backtracking(tab, x + 1, y, 0));
	else if (tab[x][y][4] != 0 && x == 3)
		return (backtracking(tab, 0, y + 1, 0));
	while (i < 4)
	{
		if (tab[x][y][i] != 0 && is_valid(tab, x, y, i + 1))
		{
			tab[x][y][4] = i + 1;
			if (x != 3)
			{
				if (backtracking(tab, x + 1, y, 0))
					return (1);
			}
			else
				if (backtracking(tab, 0, y, 0))
					return (1);
		}
		i++;
	}
	tab[x][y][4] = 0;
	return (0);
}

int	end_check(int ***tab, int x, int y)
{
	display(tab, 0, 0);
	while (y < 4)
	{
		if (tab[x][y][4] == 0)
		{
			write(2, "Error\n", 7);
			return (0);
		}
		x++;
		if (x == 4)
		{
			y++;
			x = 0;
		}
	}
	display(tab, 0, 0);
	return (0);
}

void	display(int ***tab, int x, int y)
{
	char	c;

	while (y < 4)
	{
		c = tab[x][y][4] + '0';
		write(1, &c, 1);
		if (x < 3)
			write(1, " ", 1);
		x++;
		if (x == 4)
		{
			y++;
			x = 0;
			write(1, "\n", 1);
		}
	}
	mfree(tab, 0, 0);
}
