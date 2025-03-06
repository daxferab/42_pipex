/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:21:43 by daxferna          #+#    #+#             */
/*   Updated: 2025/03/05 14:56:35 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp) // infile cmd1 cmd2 outfile
{
	pid_t	pid1;
	int		fdpipe[2];

	if (argc != 5)
		error(1);
	if (pipe(fdpipe) == -1)
		error(2);
	pid1 = fork();
	if (pid1 == -1)
	{
		close(fdpipe[0]);
		close(fdpipe[1]);
		error(3);
	}
	if (pid1 == 0)
		child_process(fdpipe, argv, envp);
	parent_process(fdpipe, argv, envp);
	wait(NULL);
	wait(NULL);
	return (0);
}
