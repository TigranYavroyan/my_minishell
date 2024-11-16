/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:43:10 by tigran            #+#    #+#             */
/*   Updated: 2024/11/16 16:41:33 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	remove_2d_str(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i] != NULL)
		free(str[i]);
	free(str);
}

void	auto_free(char **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	ft_open(char *path, int flags, int permisson)
{
	int				fd;
	struct stat		file_info;

	fd = open(path, flags, permisson);
	if (fd < 0)
	{
		if (errno == EACCES)
			__err_msg_prmt__(path, ": Permission denied", INV_ARG);
		else if (errno == ENOENT)
			__err_msg_prmt__(path, ": No such file or directory", INV_ARG);
		stat(path, &file_info);
		if (S_ISDIR(file_info.st_mode))
			__err_msg_prmt__(path, ": is a directory", DIR_ERROR);
		return (-1);
	}
	return (fd);
}
