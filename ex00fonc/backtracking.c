/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:00:34 by gangouil          #+#    #+#             */
/*   Updated: 2023/08/27 18:50:19 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	backtracking(int ***tab, int x, int y);
void	fixe_mul(int ***tab, int x, int y);
int	end_check(int ***tab, int x, int y);
int	is_valid(int ***tab, int x, int y, int fixe);
void	display(int ***tab);

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

int	end_check(int ***tab, int x, int y)
{
	int	sum;
	int	sum2;

	sum = 0;
	sum2 = 0;
	while (y < 4)
	{
		sum += tab[x][y][4];
		sum2 += tab[y][x][4];
		x++;
		if (x == 4)
		{
			x = 0;
			y++;
			if (sum != 10 || sum2 != 10)
				return (0);
			sum = 0;
			sum2 = 0;
		}
	}
	//display(tab);
	return (1);
}

void	fixe_mul(int ***tab, int x, int y)
{
	(void)x;
	(void)y;
	backtracking(tab, 0, 0);
	display(tab);
}

int	backtracking(int ***tab, int x, int y)
{
	int	i;

	if (y == 4)
		return (1);
	
	if (tab[x][y][4] != 0 && x != 3)
		return backtracking(tab, x + 1, y);
	else if (tab[x][y][4] != 0 && x == 3)
		return backtracking(tab, 0, y + 1);
	i = 0;
	while (i < 4)
	{
		if (tab[x][y][i] != 0 && is_valid(tab, x, y, i + 1))
		{
			tab[x][y][4] = i + 1;
			if (x != 3)
			{
				if (backtracking(tab, x + 1, y))
					return (1);
			}
			else
			{	
				if (backtracking(tab, 0, y))
					return (1);
			}
		}
		i++;
	}
	tab[x][y][4] = 0;
	printf("fin\n");
	return (0);
	/*int	i;

	while (y < 4 && (c == 0))
	{
		if (x > 3)
		{
			y++;
			if (y == 4)
				break;
			x = 0;
		}
		i = 0;
		while (i < 4 && (c == 0))
		{
			if (tab[x][y][i] != 0 && is_valid(tab, x, y, i + 1) && (c == 0))
			{
				tab[x][y][4] = i + 1;
				backtracking(tab, x + 1, y, c);
			}
			i++;
			if (x < 3 && tab[x + 1][y][4] != 0 && tab[x + 1][y][4] / 10 == 0)
			{
				tab[x][y][4] = 0;
				tab[x + 1][y][4] = 0;
			}
			else if (x == 3 && y != 3 && tab[0][y + 1][4] != 0 && tab[x + 1][y][4] / 10 == 0)
			{
				tab[x][y][4] = 0;
				tab[0][y + 1][4] = 0;
			}
		}
		if (tab[x][y][4] == 0)
			break;
		x++;
	}
	display(tab);
	printf("\n\n");*/
	//int test = end_check(tab, 0, 0);
	//if (test == 1)
	//	return;
	//printf("test = %d\n", test);
	//if (test == 0)
	//	printf("0 mon kho");
	//if (test == 1)
	//	printf("1 mon lapin");
	//*c = end_check(tab, 0, 0);
	/*check si somme = 10
		si c'est le cas, c = 1
		display
	si c'est pas le cas, return*/
}
