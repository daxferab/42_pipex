/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:58:43 by daxferna          #+#    #+#             */
/*   Updated: 2025/03/20 01:33:00 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*get_path(char **envp, char	*cmd)
{
	char	*line;
	char	**path_list;
	char	*path;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	line = ft_strdup(envp[i] + 5);
	if (!line)
		error(6);
	path_list = ft_split(line, ':');
	cmd = ft_strjoin("/", cmd);
	if (!path_list || !cmd)
		error(6);
	i = 0;
	while (path_list[i])
	{
		path = ft_strjoin(path_list[i++], cmd);
		if (!path)
			error(6);
		if (access(path, X_OK) == 0)
			return (free_split(path_list), free(line), path);
		free(path);
	}
	return (free_split(path_list), free(line), free(cmd), NULL);
}

void	execute(char **envp, char *argv)
{
	char	*path;
	char	**cmd_list;

	if (!ft_strncmp(argv, "", 1))
		error(6);
	cmd_list = ft_split(argv, ' ');
	if (!cmd_list)
		error(6);
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
