/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:34:46 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/14 17:29:58 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <unistd.h> // for system call write
#include <fcntl.h> // for system call open
#include <string.h> // for memmove and strlen
#include <stdio.h> // for debug printf
#include <stdbool.h> // to use bool type

# define BUFF_SIZE 1024

/*
**	DELETE BEFORE EVALUATION
*/

void	print_test(char *test);

/*
**	FUNCTIONS
*/

char	*read_file(char *file);
void	print_error(char *s);
int		ft_file_errors(char *file);

#endif
