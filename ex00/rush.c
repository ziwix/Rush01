/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:04:19 by gangouil          #+#    #+#             */
/*   Updated: 2023/08/27 21:29:37 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	first_check(int *input, int *pos, int ***tab);
void	x_check(int ***tab, int c, int x, int y);
void	y_check(int ***tab, int c, int x, int y);
void	init(int *input);
void	tab_fill(int *input, int ***tab, int y, int z);
void	middle_place(int ***tab);
void	cond_x(int ***tab, int *pos, int i, int *input);
void	cond_y(int ***tab, int *pos, int i, int *input);

void	init(int *input)
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
	tab_fill(input, tab, 0, 0);
}

void	tab_fill(int *input, int ***tab, int y, int z)
{
	int	pos[2];
	int	x;

	x = 0;
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
	pos[0] = 0;
	pos[1] = 0;
	first_check(input, pos, tab);
	middle_place(tab);
}

void	first_check(int *input, int *pos, int ***tab)
{
	int	i;

	i = -1;
	while (i++ < 8)
	{
		cond_x(tab, pos, i, input);
		pos[0]++;
		if (pos[0] == 4)
		{
			pos[1] = 3;
			pos[0] = 0;
		}
	}
	pos[0] = 0;
	pos[1] = 0;
	while (i++ < 16)
	{
		cond_y(tab, pos, i, input);
		pos[1]++;
		if (pos[1] == 4)
		{
			pos[0] = 3;
			pos[1] = 0;
		}
	}
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
		else if (c == 5)
			tab[x][y][4] = 3;
		else if (c == 6)
			tab[x][y][4] = 3;
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
		else if (c == 5)
			tab[x][y][4] = 3;
		else if (c == 6)
			tab[x][y][4] = 3;
		i++;
	}
}
