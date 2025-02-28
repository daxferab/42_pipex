/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:58:43 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/28 19:29:46 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*get_path(char **envp, char	*cmd)
{
	char	*path_line;
	char	**path_split;
	char	*path;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path_line = ft_strdup(envp[i] + 5); //TODO: Liberar
	path_split = ft_split(path_line, ':'); //TODO: Liberar
	i = 0;
	while (path_split[i])
	{
		path = ft_strjoin(path_split[i], cmd); //TODO: Liberar
		if (access(path, F_OK) == 0)
			return (path); //TODO: Liberar
		i++;
	}
	//TODO: Liberar
	return ((char *)-1);
}

void	execute(char **envp, char *argv)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' '); //TODO: Liberar
	path = get_path(envp, cmd[0]); //TODO: Proteger get_path
	execve(path, cmd, envp); //TODO: Proteger execve
}
