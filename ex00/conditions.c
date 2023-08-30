/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:01:03 by gangouil          #+#    #+#             */
/*   Updated: 2023/08/27 19:04:48 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	cond_x(int ***tab, int *pos, int i, int *input);
void	cond_y(int ***tab, int *pos, int i, int *input);
void	x_check(int ***tab, int c, int x, int y);
void	y_check(int ***tab, int c, int x, int y);

void	cond_x(int ***tab, int *pos, int i, int *input)
{
	if (i < 4 && input[i] == 4 && input[i + 4] == 1)
		x_check(tab, 1, pos[0], pos[1]);
	if (i >= 4 && input[i] == 4 && input[i - 4] == 1)
		x_check(tab, 2, pos[0], pos[1]);
	else if (i < 4 && input[i] == 2 && input[i + 4] == 1)
		x_check(tab, 5, pos[0], pos[1]);
	else if (i >= 4 && input[i] == 2 && input[i - 4] == 1)
		x_check(tab, 6, pos[0], pos[1]);
	else if (input[i] == 1)
		tab[pos[0]][pos[1]][4] = 4;
	else if (input[i] == 2)
		x_check(tab, 3, pos[0], pos[1]);
	else if (input[i] == 3)
		x_check(tab, 4, pos[0], pos[1]);
}

void	cond_y(int ***tab, int *pos, int i, int *input)
{
	if (i < 12 && input[i] == 4 && input[i + 4] == 1)
		y_check(tab, 1, pos[0], pos[1]);
	if (i >= 12 && input[i] == 4 && input[i - 4] == 1)
		y_check(tab, 2, pos[0], pos[1]);
	else if (i < 12 && input[i] == 2 && input[i + 4] == 1)
		x_check(tab, 5, pos[0], pos[1]);
	else if (i >= 12 && input[i] == 2 && input[i - 4] == 1)
		x_check(tab, 6, pos[0], pos[1]);
	else if (input[i] == 1)
		tab[pos[0]][pos[1]][4] = 4;
	else if (input[i] == 2)
		y_check(tab, 3, pos[0], pos[1]);
	else if (input[i] == 3)
		y_check(tab, 4, pos[0], pos[1]);
}
