/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:58:43 by daxferna          #+#    #+#             */
/*   Updated: 2025/03/03 20:29:00 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*get_path(char **envp, char	*cmd)
{
	char	*path_line;
	char	**path_split;
	char	*path;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path_line = ft_strdup(envp[i] + 5); //TODO: Liberar
	path_split = ft_split(path_line, ':'); //TODO: Liberar
	cmd = ft_strjoin("/", cmd); //TODO: Liberar
	i = 0;
	while (path_split[i])
	{
		path = ft_strjoin(path_split[i], cmd); //TODO: Liberar
		if (access(path, X_OK) == 0)
			return (path); //TODO: Liberar
		i++;
	}
	//TODO: Liberar
	return (NULL);
}

void	execute(char **envp, char *argv)
{
	char	*path;
	char	**cmd;

	if (!ft_strncmp(argv, "", 1))
		error(6);
	cmd = ft_split(argv, ' '); //TODO: Liberar
	path = get_path(envp, cmd[0]); //TODO: Proteger get_path
	if (path == NULL)
		error(6);
	execve(path, cmd, envp); //TODO: Proteger execve
}
