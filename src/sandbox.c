/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:02:38 by jhii              #+#    #+#             */
/*   Updated: 2022/11/14 16:44:32 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sandbox.h"

int	ft_printerror(char *str, char *arg)
{
	write(2, str, ft_strlen(str));
	if (arg)
		write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
	return (1);
}

int	ft_execute(char **argv, int i, int lastfd, char **envp)
{
	argv[i] = NULL;
	dup2(lastfd, 0);
	close(lastfd);
	execve(argv[0], argv, envp);
	return (ft_printerror("error: cannot execute ", argv[0]));
}

int	sandbox(int argc, char **argv, char **envp)
{
	int	i;
	int	fd[2];
	int	lastfd;

	i = 0;
	lastfd = dup(0);
	(void)argc;

	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				ft_printerror("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				ft_printerror("error: cd: cannot change directiory to ", argv[1]);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (ft_execute(argv, i, lastfd, envp))
					return (1);
			}
			else
			{
				close(lastfd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				lastfd = dup(0);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(argv, i, lastfd, envp))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(lastfd);
				lastfd = fd[0];
			}
		}
	}
	close(lastfd);
	return (0);
}
