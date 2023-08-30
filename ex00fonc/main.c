/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:03:30 by gangouil          #+#    #+#             */
/*   Updated: 2023/08/27 14:14:13 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init(int *input, int x, int y, int z);
int		*verify(char **argv, int *j, int i, int *input);

int	main(int argc, char **argv)
{
	int	input[16];
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (argc != 2)
	{	
		write(2, "Error\n", 7);
		return (0);
	}
	if (verify(argv, &j, i, input) == 0)
		return (0);
	if (j != 16)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	init(input, 0, 0, 0);
	return (0);
}

int	*verify(char **argv, int *j, int i, int *input)
{
	while (argv[1][i])
	{
		if (i > 30)
		{
			write(2, "Error\n", 7);
			return (0);
		}
		if (argv[1][i] >= '1' && argv[1][i] <= '4'
			&& (argv[1][i + 1] == ' ' || argv[1][i + 1] == 0))
		{
			input[*j] = argv[1][i] - '0';
			*j = *j + 1;
			i++;
		}
		else if (argv[1][i] == ' ')
			i++;
		else
		{
			write(2, "Error\n", 7);
			return (0);
		}
	}
	return (input);
}
