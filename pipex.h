/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:58:49 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/28 19:04:58 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "libft/libft.h"
# include <sys/wait.h>

// errors.c
void	error(int code);

// execution.c
void	execute(char **envp, char *argv);

// processes.c
void	child_process(int *pipe, char **argv, char **envp);
int		parent_process(int *pipe, char **argv, char **envp);

#endif
