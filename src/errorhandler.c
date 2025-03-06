/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:24:00 by daxferna          #+#    #+#             */
/*   Updated: 2025/03/05 14:50:23 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
}

void	error(int code, int errno)
{
	if (code == 1)
	{
		ft_putstr_fd("Error. Wrong number of arguments\n", 2);
		ft_putstr_fd("Correct usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
	}
	if (code == 2)
		ft_putstr_fd("Error. Pipe failed\n", 2);
	if (code == 3)
		ft_putstr_fd("Error. Fork failed\n", 2);
	if (code == 4)
		ft_putstr_fd("Error. Couldn't read infile\n", 2);
	if (code == 5)
		ft_putstr_fd("Error. Couldn't read outfile\n", 2);
	if (code == 6)
		ft_putstr_fd("Error. Command not found\n", 2);
	if (code == 7)
		ft_putstr_fd("Error. Dup2 failed\n", 2);
	if (code == 8)
		ft_putstr_fd("Error. Execution failed", 2);
	exit(errno);
}

//FIXME: If outfile is empty at the end of the program, exit code 1
//FIXME: If outfile can`t be accessed, exit code 1
//FIXME: If second cmd doesn`t exist, leaks and wrong exit (has to be 127)
//FIXME: If flags on second command dont exist, exit 1
