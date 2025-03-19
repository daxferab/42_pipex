/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:58:43 by daxferna          #+#    #+#             */
/*   Updated: 2025/03/19 03:26:13 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*get_path(char **envp, char	*cmd)
{
	char	*line;
	char	**path_split;
	char	*path;
	char	*cmd2;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	line = ft_strdup(envp[i] + 5);
	path_split = ft_split(line, ':');
	cmd2 = ft_strjoin("/", cmd);
	i = 0;
	while (path_split[i])
	{
		path = ft_strjoin(path_split[i], cmd2);
		if (access(path, X_OK) == 0)
			return (free_split(path_split), free(line), path);
		free(path);
		i++;
	}
	return (free_split(path_split), free(line), free(cmd2), NULL);
}

void	execute(char **envp, char *argv)
{
	char	*path;
	char	**cmd_list;

	if (!ft_strncmp(argv, "", 1))
		error(6);
	cmd_list = ft_split(argv, ' ');
	path = get_path(envp, cmd_list[0]);
	if (path == NULL)
	{
		free_split(cmd_list);
		error(6);
	}
	if (execve(path, cmd_list, envp) == -1)
	{
		free_split(cmd_list);
		error(8);
	}
}
