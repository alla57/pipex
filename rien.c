char	*get_path(char **env, char *given_path, char *cmd)
{
	int		i;
	char	*env_path;
	char	**paths;
	char	*cmd_path;

	i = 0;
	if (!access(given_path, F_OK))
		return (given_path);
	while (ft_strncmp(env[i], "PATH=", 5) && env[i])
		++i;
	if (!env[i])
	{
		ft_putstr_fd("environement error !", 1);
		return (NULL);
	}
	env_path = env[i];
	env_path += 5;
	paths = ft_split(env_path, ':');
	i = 0;
	cmd_path = ft_strjoin(paths[i], cmd);
	while (paths[i] && access(cmd_path, F_OK))
	{
		free(cmd_path);
		cmd_path = ft_strjoin(paths[++i], cmd);
	}
	if (!paths[i])
	{
		free(cmd_path);
		return (ft_putstr_fd("command not found !"));
	}
	return (cmd_path);
}

arg_cmd = ft_split(argv[2], ' '); //modify later by argv[2]
	if (!(cmd_path = get_path(env, arg_cmd[0])))
		return (0);
	pid = fork();
	if (pid == 0)
	{
		execve(cmd_path, arg_cmd, env);
		free(cmd_path);
		ft_free_double((void**)arg_cmd);
	}
	else
		wait(&status);

			/*
	if (pid == 0)
	{
		arg_cmd = ft_split(argv[2], ' ');
		if (!(cmd_path = get_path(env, arg_cmd[0])))
			return (0);
		dup2(fd, 0);
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		execve(cmd_path, arg_cmd, env);
	}
	else
	{
		wait(&status);
		arg_cmd = ft_split(argv[3], ' ');
		if (!(cmd_path = get_path(env, arg_cmd[0])))
			return (0);
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		execve(cmd_path, arg_cmd, env);
		free(cmd_path);
		ft_free_double((void**)arg_cmd);
	}*/
	