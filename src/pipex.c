/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:48:08 by user42            #+#    #+#             */
/*   Updated: 2021/10/11 22:41:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int read_file(char *path, int mode)
{
	int fd;

	if (mode)
	{
		if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
		{
			ft_putstr_fd("output file problem", 1);
			return (-1);
		}
	}
	else
	{
		if ((fd = open(path, O_RDONLY)) == -1)
		{
			ft_putstr_fd("input file not found", 1);
			return (-1);
		}
	}
	return (fd);
}

char *check_cmd(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*tmp;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!(access(cmd_path, F_OK)))
			return (cmd_path);
		free(cmd_path);
	}
	ft_putstr_fd("command not found !", 1);
	return (NULL);
}

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
	ft_free_double((void**)paths);
	return (cmd_path);
}

int exec_n_free(char *cmd_path, char **arg_cmd, char **env)
{
	pid_t pid;
	int status;

	if ((pid = fork()) < 0)
		return (0);
	if (pid == 0)
		execve(cmd_path, arg_cmd, env);
	wait(&status);
	ft_free_double((void**)arg_cmd);
	free(cmd_path);
	return (0);
}

int parent(char **env, int fd, int *pipe_fd, char **argv)
{
	char **arg_cmd;
	char *cmd_path;
	int status;

	wait(&status);
	arg_cmd = ft_split(argv[3], ' ');
	if (!(cmd_path = get_path(env, arg_cmd[0])))
		return (0);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	dup2(fd, 1);
	close(fd);
	exec_n_free(cmd_path, arg_cmd, env);
	return (0);
}

int child(char **env, int fd, int *pipe_fd, char **argv)
{
	char **arg_cmd;
	char *cmd_path;

	arg_cmd = ft_split(argv[2], ' ');
	if (!(cmd_path = get_path(env, arg_cmd[0])))
		return (0);
	dup2(fd, 0);
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	exec_n_free(cmd_path, arg_cmd, env);
	return (0);
}

int main(int argc, char **argv, char **env)
{
	int fd;
	int pipe_fd[2];
	pid_t pid;

	if (argc != 5)
	{
		ft_putstr_fd("wrong number of arguments", 1);
		return (0);
	}
	if (pipe(pipe_fd) == -1)
		return (0);
	if ((pid = fork()) < 0)
		return (0);
	if (pid == 0)
	{
		fd = read_file(argv[1], 0);
		child(env, fd, pipe_fd, argv);
	}
	else
	{
		fd = read_file(argv[4], 1);
		parent(env, fd, pipe_fd, argv);
	}
	return (0);
}