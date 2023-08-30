/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:19 by gangouil          #+#    #+#             */
/*   Updated: 2023/08/27 14:14:02 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	first_check(int *input, int x, int y, int ***tab);
void	second_check(int *input, int x, int y, int ***tab);
void	x_check(int ***tab, int c, int x, int y);
void	y_check(int ***tab, int c, int x, int y);
void	init(int *input, int x, int y, int z);
void	display(int ***tab);
void	middle_place(int ***tab);

void	display(int ***tab)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (y < 4)
	{
		if (tab[x][y][4] != 0)
			printf("%d ", tab[x][y][4]);
		else if (tab[x][y][0] == 0)
			printf("0 ");
		else
		{
			while (count < 4)
			{
				printf("%d", tab[x][y][count]);
				count++;
			}
			printf(" ");
		}
		count = 0;
		x++;
		if (x == 4)
		{
			printf("\n");
			x = 0;
			y++;
		}
	}
	(void)tab;
}

void	init(int *input, int x, int y, int z)
{
	int	***tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = malloc(4 * sizeof(int **));
	while (i < 4)
	{
		tab[i] = malloc(sizeof(int *) * 4);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tab[i][j] = malloc(sizeof(int) * 5);
		j++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
	}
	while (x < 4)
	{
		while (y < 4)
		{
			while (z < 5)
			{
				tab[x][y][z] = 0;
				z++;
			}
			z = 0;
			y++;
		}
		y = 0;
		x++;
	}
	x = 0;
	y = 0;
	first_check(input, x, y, tab);
}

void	first_check(int *input, int x, int y, int ***tab)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (i < 4 && input[i] == 4 && input[i + 4] == 1)
			x_check(tab, 1, x, y);
		if (i >= 4 && input[i] == 4 && input[i - 4] == 1)
			x_check(tab, 2, x, y);
		else if (input[i] == 1)
			tab[x][y][4] = 4;
		else if (input[i] == 2)
			x_check(tab, 3, x, y);
		else if (input[i] == 3)
			x_check(tab, 4, x, y);
		x++;
		i++;
		if (i == 4)
		{
			y = 3;
			x = 0;
		}
	}
	second_check(input, 0, 0, tab);
}

void	second_check(int *input, int x, int y, int ***tab)
{
	int	i;

	i = 8;
	while (i < 16)
	{
		if (i < 12 && input[i] == 4 && input[i + 4] == 1)
			y_check(tab, 1, x, y);
		if (i >= 12 && input[i] == 4 && input[i - 4] == 1)
			y_check(tab, 2, x, y);
		else if (input[i] == 1)
			tab[x][y][4] = 4;
		else if (input[i] == 2)
			y_check(tab, 3, x, y);
		else if (input[i] == 3)
			y_check(tab, 4, x, y);
		y++;
		i++;
		if (i == 12)
		{
			x = 3;
			y = 0;
		}
	}
	middle_place(tab);
}

void	y_check(int ***tab, int c, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (c == 1 && tab[x][y][4] == 1)
			tab[i][y][4] = i + 1;
		else if (c == 2 && tab[x + 3][y][4] == 4)
			tab[3 - i][y][4] = i + 1;
		else if (c == 3 && i < 3)
			tab[x][y][i] = i + 1;
		else if (c == 4 && i < 2)
		{
			tab[x][y][i] = i + 1;
			tab[x][y][2] = 0;
		}
		i++;
	}
}

void	x_check(int ***tab, int c, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (c == 1)
			tab[x][i][4] = i + 1;
		else if (c == 2)
			tab[x][3 - i][4] = i + 1;
		else if (c == 3 && i < 3)
			tab[x][y][i] = i + 1;
		else if (c == 4 && i < 2)
			tab[x][y][i] = i + 1;
		i++;
	}
}
