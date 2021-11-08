/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:02:49 by alla              #+#    #+#             */
/*   Updated: 2021/11/08 16:35:06 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_path(char **env, char *cmd)
{
	int		i;
	char	**paths;
	char	*cmd_path;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		++i;
	if (!env[i])
	{
		ft_putstr_fd("environement error !", 1);
		return (NULL);
	}
	paths = ft_split(env[i] + 5, ':');
	cmd_path = check_cmd(paths, cmd);
	ft_free_double((void **)paths);
	return (cmd_path);
}

int	exec_n_free(char *cmd_path, char **arg_cmd, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
		execve(cmd_path, arg_cmd, env);
	wait(&status);
	ft_free_double((void **)arg_cmd);
	free(cmd_path);
	return (0);
}
