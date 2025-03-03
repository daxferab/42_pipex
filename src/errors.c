/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:24:00 by daxferna          #+#    #+#             */
/*   Updated: 2025/03/03 20:23:48 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error(int code)
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
		ft_putstr_fd("Error. Infile failed\n", 2);
	if (code == 5)
		ft_putstr_fd("Error. Outfile failed\n", 2);
	if (code == 6)
		ft_putstr_fd("Error. Command not found\n", 2);
	exit(1);
}
