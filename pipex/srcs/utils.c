/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:53:59 by ggispert          #+#    #+#             */
/*   Updated: 2024/02/01 12:36:36 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int _open(char *file, char wr)
{
	int fd;

	if (wr)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (access(file, W_OK))
			ft_error(2, PIPEX, file);
	}
	else
		fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(EXIT_FAILURE, PIPEX, file);
	return (fd);
}

void _close(int fd)
{
	int close_value;

	close_value = close(fd);
	if (close_value == -1)
		ft_error(EXIT_FAILURE, PIPEX, ft_itoa(fd)); //CHECK IF ERROR
}

char *get_path(char **envp)
{
	int i;
	char *path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i] + 5); //CHECK IF ERROR
			return (path);
		}
		i++;
	}
	return ("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
}

void add_slash(char ***path)
{
	int i;

	i = 0;
	while (*path && (*path)[i])
	{
		char *tmp = ft_strjoin((*path)[i], "/"); //CHECK IF ERROR
		free((*path)[i]);
		(*path)[i] = tmp;
		i++;
	}
}

void	ft_error(int exit_code, char *source, char *additional_info)
{
	ft_putstr_fd(source, 2);
	perror(additional_info);
	exit(exit_code);
}

void	ft_custom_error(int exit_code, char *source, char *reason, char *additional_info)
{
	ft_putstr_fd(source, 2);
	if (additional_info)
		ft_putstr_fd(ft_strjoin(additional_info, ": "), 2);
	ft_putendl_fd(reason, 2);
	exit(exit_code);
}
