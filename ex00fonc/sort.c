/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:45:14 by gangouil          #+#    #+#             */
/*   Updated: 2023/08/27 17:53:42 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	possib_sort(int ***tab);
void	display(int ***tab);
void	middle_place(int ***tab);
void	fixe_mul(int ***tab, int x, int y);

void	middle_place(int ***tab)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 1;
	while (i < 3)
	{
		k = 0;
		while (k < 4)
		{	
			tab[i][j][k] = k + 1;
			k++;
		}
		i++;
		if (i == 3 && j == 1)
		{
			i = 1;
			j++;
		}
	}
	possib_sort(tab);
	fixe_mul(tab, 0, 0);
	//display(tab);
}

void	possib_sort(int ***tab)
{
	int	i;
	int	x;
	int	y;
	int	i_save;

	i = -1;
	x = 0;
	y = 0;
	while (i++ < 14 && y < 4)
	{
		i_save = i;
		if (tab[x][y][4] != 0)
		{
			i = -1;
			while (i++ < 3)
				tab[i][y][tab[x][y][4] - 1] = 0;
			i = -1;
			while (i++ < 3)
				tab[x][i][tab[x][y][4] - 1] = 0;
			i = i_save;
		}
		x++;
		if (x == 3)
		{
			x = 0;
			y++;
		}
	}
	display(tab);
}
