/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:41:21 by apetitco          #+#    #+#             */
/*   Updated: 2024/02/13 19:52:14 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * 
*/
void	exec(char *cmd, char *envp[])
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], envp);
	if (execve(path, s_cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
		ft_putendl_fd(s_cmd[0], STDERR_FILENO);
		ft_free_tab(s_cmd);
		exit(0);
	}
}

/**
 * 
*/
void	child(char *argv[], int *p_fd, char *envp[])
{
	int	fd;

	fd = open_file(argv[1], 0);
	dup2(fd, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[0]);
	execute(argv[2], envp);
}

/**
 * 
*/
void	parent(char *argv[], int *p_fd, char *envp[])
{
	int	fd;

	fd = open_file(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[1]);
	execute(argv[3], envp);
}

/**
 * 
*/
int	main(int argc, char *argv[], char *envp[])
{
	int		p_fd[2];
	pid_t	pid;
	
	if (argc != 5)
	{
		exit_handler(1);
	}
	if (pipe(p_fd) == -1)
	{
		exit(-1);
	}
	pid = fork();
	if (pid == 0)
	{
		child(argc, p_fd, envp);
	}
	parent(argc, p_fd, envp);
	return (0);
}