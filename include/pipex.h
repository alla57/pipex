/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:22:17 by user42            #+#    #+#             */
/*   Updated: 2021/11/08 16:50:07 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "../Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>

int		child(char **env, int fd, int *pipe_fd, char **argv);
int		parent(char **env, int fd, int *pipe_fd, char **argv);
int		exec_n_free(char *cmd_path, char **arg_cmd, char **env);
char	*get_path(char **env, char *cmd);
char	*check_cmd(char **paths, char *cmd);
int		read_file(char *path, int mode);

#endif