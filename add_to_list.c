/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:20:53 by hulamy            #+#    #+#             */
/*   Updated: 2019/04/15 13:41:06 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		start_line(char **square)
{
	int i;
	int x;

	i = 4;
	x = -1;
	while (x < 4 && i == 4 && !(i = 0) && square[++x][0] != '#')
		while (i < 4 && square[x][i] != '#')
			i++;
	return (x);
}

int		start_column(char **square)
{
	int i;
	int x;

	i = 4;
	x = -1;
	while (x < 4 && i == 4 && !(i = 0) && square[0][++x] != '#')
		while (i < 4 && square[i][x] != '#')
			i++;
	return (x);
}

int		end_line(char **square)
{
	int i;
	int x;

	i = -1;
	x = 4;
	while (x >= 0 && i == -1 && (i = 3) && square[--x][3] != '#')
		while (i >= 0 && square[x][i] != '#')
			i--;
	return (x);
}

int		end_column(char **square)
{
	int i;
	int x;

	i = -1;
	x = 4;
	while (x < 4 && i == 4 && !(i = 0) && square[++x][0] != '#')
		while (i < 4 && square[x][i] != '#')
			i++;
	return (x);
}

char	**fill_tetraminos(char **square, int x1, int y1, int x2, int y2)
{
	char	**result;
	int		height;
	int		length;
	int		i;
	int		j;

	i = 0;
	height = x2 - x1 + 1;
	length = y2 - y1 + 1;
	if (!(result = (char**)malloc(sizeof(*result) * (height + 1))))
		return (NULL);
	while (i < 4)
	{
		if (!(result[i] = (char*)malloc(sizeof(**result) * (length + 1))))
			return (NULL);
		result[i][length] = '\0';
		i++;
	}
	i = -1;
	while (++i < height && (j = -1))
		while (++j < length)
			result[i][j] = square[x1 + i][y1 + j];
	return (result);
}

void	find_start_and_end(char **square, int **x)
{
	int i;

	x[0][0] = -1;	// x1
	x[0][1] = -1;	// y1
	x[0][2] = 4;	// x2
	x[0][3] = 4;	// y2
	i = 4;
	while (x[0][0] < 4 && i == 4 && !(i = 0) && square[++(x[0][0])][0] != '#')
		while (i < 4 && square[*(x[0])][i] != '#')
			i++;
	i = 4;
	while (x[0][1] < 4 && i == 4 && !(i = 0) && square[0][++(x[0][1])] != '#')
		while (i < 4 && square[i][x[0][1]] != '#')
			i++;
	i = -1;
	while (x[0][2] >= 0 && i == -1 && (i = 3) && square[--(x[0][2])][3] != '#')
		while (i >= 0 && square[x[0][2]][i] != '#')
			i--;
	i = -1;
	while (x[0][3] >= 0 && i == -1 && (i = 3) && square[3][--(x[0][3])] != '#')
		while (i >= 0 && square[i][x[0][3]] != '#')
			i--;
}

int		add_to_list(char **square, t_fillist *list)
{
	int	*tab;
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	tab = (int*)malloc(sizeof(int) * 4);
	find_start_and_end(square, &tab);
	x1 = tab[0];
	y1 = tab[1];
	x2 = tab[2];
	y2 = tab[3];
	printf("%d %d %d %d\n", x1, y1, x2, y2);

//	x1 = start_line(square);
//	y1 = start_column(square);
//	x2 = end_line(square);
//	y2 = end_column(square);
	list->size[0] = y2 - y1 + 1;
	list->size[1] = x2 - x1 + 1;
	list->area = list->size[0] * list->size[1];
	list->tetraminos = fill_tetraminos(square, x1, y1, x2, y2);
	return (0);
}

int		main(int ac, char **av)
{
	static t_fillist	*list;
	int					i;

	i = -1;
	if (!(list = (t_fillist*)malloc(sizeof(*list))))
		return (0);
	if (ac > 4)
	{
		add_to_list(++av, list);
		while (++i < list->size[1])
			printf("%s\n", list->tetraminos[i]);
	}

	return (0);
}