/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:21:43 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/28 02:16:28 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void child_process(int *pipe, char **argv, char **envp) //Ejecuta cmd1 en infile y escribe en fdpipe[1]
{
	close(pipe[0]);
	//TODO: Resto de la función
}

void parent_process(int *pipe, char **argv, char **envp) //Ejecuta cmd2 en fdpipe[0] y escribe en outfile
{
	close(pipe[1]);
	wait(NULL);
	//TODO: Resto de la función
}

int	main(int argc, char **argv, char **envp)
{
	pid_t pid1;
	int fdpipe[2];

	// if (argc != 5)
	// 	error(1);
	if (pipe(fdpipe) == -1)
		error(2);
	pid1 = fork();
	if (pid1 == -1)
		error(3);
	else if (pid1 == 0)
		child_process(fdpipe, argv, envp);
	else
		parent_process(fdpipe, argv, envp);
	return (0);
}
