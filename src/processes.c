/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:56:08 by daxferna          #+#    #+#             */
/*   Updated: 2025/03/04 16:55:31 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(int *pipe, char **argv, char **envp)
{
	int	fdin;

	close(pipe[0]);
	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
		error(4);
	if (dup2(fdin, STDIN_FILENO) == -1 || dup2(pipe[1], STDOUT_FILENO) == -1)
	{
		close(pipe[1]);
		close(fdin);
		error(7);
	}
	close(pipe[1]);
	close(fdin);
	execute(envp, argv[2]);
}

int	parent_process(int *pipe, char **argv, char **envp)
{
	int	pid2;
	int	fdout;

	close(pipe[1]);
	pid2 = fork();
	if (pid2 == -1)
		error(3);
	if (pid2 == 0)
	{
		fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fdout == -1)
			error(5);
		if (dup2(pipe[0], STDIN_FILENO) == -1
			|| dup2(fdout, STDOUT_FILENO) == -1)
		{
			close(pipe[0]);
			close(fdout);
			error(7);
		}
		close(pipe[0]);
		close(fdout);
		execute(envp, argv[3]);
	}
	return (0);
}
